; NOTE: Assertions have been autogenerated by utils/update_test_checks.py UTC_ARGS: --version 2
; RUN: opt -O3 -S < %s | FileCheck %s

; Arg promotion eliminates the struct argument, and eliminates dead arguments, but introduces and leaves dead loads of the eliminated dead arg in callers

%struct.ss = type { ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr, ptr }

define internal void @phantomLoad(ptr %p, ptr %y, ptr %x) {
entry:
  %0 = load i32, ptr %x
  store i32 %0, ptr %y
  ret void
}

define ptr @parent(ptr align 8 dereferenceable(72) %f, i16 %val1, i16 %val2, i32 %val3) align 2 {
; CHECK-LABEL: define noundef nonnull ptr @parent
; CHECK-SAME: (ptr readonly returned align 8 captures(ret: address, provenance) dereferenceable(72) [[F:%.*]], i16 [[VAL1:%.*]], i16 [[VAL2:%.*]], i32 [[VAL3:%.*]]) local_unnamed_addr #[[ATTR0:[0-9]+]] align 2 {
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds nuw i8, ptr [[F]], i64 64
; CHECK-NEXT:    [[F_VAL:%.*]] = load ptr, ptr [[TMP0]], align 8
; CHECK-NEXT:    [[CMP_NOT_NOT_I:%.*]] = icmp eq i32 [[VAL3]], 0
; CHECK-NEXT:    [[SPEC_SELECT_I:%.*]] = select i1 [[CMP_NOT_NOT_I]], i16 [[VAL1]], i16 [[VAL2]]
; CHECK-NEXT:    [[SPEC_SELECT2_I:%.*]] = select i1 [[CMP_NOT_NOT_I]], i16 [[VAL2]], i16 [[VAL1]]
; CHECK-NEXT:    store i16 [[SPEC_SELECT_I]], ptr [[F_VAL]], align 2
; CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds nuw i8, ptr [[F_VAL]], i64 16
; CHECK-NEXT:    store i16 [[SPEC_SELECT2_I]], ptr [[TMP1]], align 2
; CHECK-NEXT:    ret ptr [[F]]
;
entry:
  call void @badChild(ptr align 8 dereferenceable(72) %f, i16 %val1, i16 %val2, i32 %val3) #4
  ret ptr %f
}

define internal void @badChild(ptr align 8 dereferenceable(72) %this, i16 %val1, i16 %val2, i32 %val3) align 2 {
entry:
  %othergep = getelementptr inbounds %struct.ss, ptr %this, i64 0, i32 2
  %load0 = load ptr, ptr %othergep, align 8
  %load2 = load ptr, ptr %this
  %x = alloca i32
  %y = alloca i32
  call void @phantomLoad(ptr %load0, ptr %x, ptr %y)
  call void @phantomLoad(ptr %load2, ptr %x, ptr %y)
  %cmp.not.not = icmp eq i32 %val3, 0
  br i1 %cmp.not.not, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %0 = getelementptr inbounds %struct.ss, ptr %this, i64 0, i32 8
  %1 = load ptr, ptr %0, align 8
  store i16 %val1, ptr %1, align 2
  %add.ptr.i.i.i.i = getelementptr inbounds i8, ptr %1, i64 16
  store i16 %val2, ptr %add.ptr.i.i.i.i, align 2
  br label %if.end

if.else:                                          ; preds = %entry
  %2 = getelementptr inbounds %struct.ss, ptr %this, i64 0, i32 8
  %3 = load ptr, ptr %2, align 8
  %add.ptr.i.i.i.i7 = getelementptr inbounds i8, ptr %3, i64 16
  store i16 %val1, ptr %add.ptr.i.i.i.i7, align 2
  store i16 %val2, ptr %3, align 2
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  ret void
}

