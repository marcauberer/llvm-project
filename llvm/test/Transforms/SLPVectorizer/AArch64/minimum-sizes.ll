; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt -S -passes=slp-vectorizer < %s | FileCheck %s

target datalayout = "e-m:e-i64:64-i128:128-n32:64-S128"
target triple = "aarch64--linux-gnu"

; This test ensures that we do not regress due to PR26364. The vectorizer
; should not compute a smaller size for %k.13 since it is in a use-def cycle
; and cannot be demoted.
;
define fastcc void @PR26364(i1 %arg) {
; CHECK-LABEL: @PR26364(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    br i1 %arg, label [[FOR_END11:%.*]], label [[FOR_COND4:%.*]]
; CHECK:       for.cond4:
; CHECK-NEXT:    [[K_13:%.*]] = phi i32 [ undef, [[ENTRY:%.*]] ], [ [[K_3:%.*]], [[FOR_COND4]] ]
; CHECK-NEXT:    [[E_02:%.*]] = phi i32 [ 1, [[ENTRY]] ], [ 0, [[FOR_COND4]] ]
; CHECK-NEXT:    [[E_1:%.*]] = select i1 undef, i32 [[E_02]], i32 0
; CHECK-NEXT:    [[K_3]] = select i1 undef, i32 [[K_13]], i32 undef
; CHECK-NEXT:    br label [[FOR_COND4]]
; CHECK:       for.end11:
; CHECK-NEXT:    ret void
;
entry:
  br i1 %arg, label %for.end11, label %for.cond4

for.cond4:
  %k.13 = phi i32 [ undef, %entry ], [ %k.3, %for.cond4 ]
  %e.02 = phi i32 [ 1, %entry ], [ 0, %for.cond4 ]
  %e.1 = select i1 undef, i32 %e.02, i32 0
  %k.3 = select i1 undef, i32 %k.13, i32 undef
  br label %for.cond4

for.end11:
  ret void
}

; This test ensures that we do not regress due to PR26629. We must look at
; every root in the vectorizable tree when computing minimum sizes since one
; root may require fewer bits than another.
;
define void @PR26629(ptr %c, i1 %arg) {
; CHECK-LABEL: @PR26629(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    br i1 %arg, label [[FOR_PH:%.*]], label [[FOR_END:%.*]]
; CHECK:       for.ph:
; CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[C:%.*]], align 4
; CHECK-NEXT:    br label [[FOR_BODY:%.*]]
; CHECK:       for.body:
; CHECK-NEXT:    [[D:%.*]] = phi i72 [ 576507472957710340, [[FOR_PH]] ], [ [[BF_SET17:%.*]], [[FOR_BODY]] ]
; CHECK-NEXT:    [[SUB:%.*]] = sub i32 [[TMP0]], undef
; CHECK-NEXT:    [[BF_CLEAR13:%.*]] = and i72 [[D]], -576460748008464384
; CHECK-NEXT:    [[TMP1:%.*]] = zext i32 [[SUB]] to i72
; CHECK-NEXT:    [[BF_VALUE15:%.*]] = and i72 [[TMP1]], 8191
; CHECK-NEXT:    [[BF_CLEAR16:%.*]] = or i72 [[BF_VALUE15]], [[BF_CLEAR13]]
; CHECK-NEXT:    [[BF_SET17]] = or i72 [[BF_CLEAR16]], undef
; CHECK-NEXT:    br label [[FOR_BODY]]
; CHECK:       for.end:
; CHECK-NEXT:    ret void
;
entry:
  br i1 %arg, label %for.ph, label %for.end

for.ph:
  %0 = load i32, ptr %c, align 4
  br label %for.body

for.body:
  %d = phi i72 [ 576507472957710340, %for.ph ], [ %bf.set17, %for.body ]
  %sub = sub i32 %0, undef
  %bf.clear13 = and i72 %d, -576460748008464384
  %1 = zext i32 %sub to i72
  %bf.value15 = and i72 %1, 8191
  %bf.clear16 = or i72 %bf.value15, %bf.clear13
  %bf.set17 = or i72 %bf.clear16, undef
  br label %for.body

for.end:
  ret void
}
