; RUN: llc < %s -mtriple=i686-pc-win32 | FileCheck %s

; PR26575
; Assertion `(Disp->isImm() || Disp->isGlobal()) && (Other.Disp->isImm() || Other.Disp->isGlobal()) && "Address displacement operand is always an immediate or a global"' failed.

target datalayout = "e-m:x-p:32:32-i64:64-f80:32-n8:16:32-a:0:32-S32"
target triple = "i686-pc-windows-msvc"

declare void @llvm.memcpy.p0.p0.i32(ptr nocapture, ptr nocapture readonly, i32, i1) argmemonly nounwind
declare <2 x i64> @_mm_xor_si128(<2 x i64>, <2 x i64>) optsize
declare <2 x i64> @llvm.x86.pclmulqdq(<2 x i64>, <2 x i64>, i8) nounwind readnone
declare <4 x float> @_mm_castsi128_ps(<2 x i64>) optsize

; Check that the LEA optimization pass works with CPI address displacements.
define void @test1(ptr nocapture readonly %src, i32 %len) #0 {
  %parts = alloca [4 x i32], align 4
  call void @llvm.memcpy.p0.p0.i32(ptr %parts, ptr %src, i32 %len, i1 false)
  %call0 = tail call <2 x i64> @_mm_xor_si128(<2 x i64> undef, <2 x i64> <i64 -9187201950435737472, i64 -9187201950435737472>)
  %tmp0 = tail call <2 x i64> @llvm.x86.pclmulqdq(<2 x i64> undef, <2 x i64> <i64 7631803798, i64 5708721108>, i8 16)
  %call1 = tail call <4 x float> @_mm_castsi128_ps(<2 x i64> %tmp0)
  ret void
; CHECK-LABEL: test1:
; CHECK:	movl %esp,
; CHECK:	calll _memcpy
; CHECK:	movaps __xmm@{{[0-9a-f]+}}, %xmm1
; CHECK:	calll __mm_xor_si128
; CHECK:	pclmulqdq $16, __xmm@{{[0-9a-f]+}}, %xmm0
; CHECK:	jmp __mm_castsi128_ps
}

declare i32 @GetLastError(...)
declare void @IsolationAwareDeactivateActCtx(i32, i32)
declare ptr @llvm.localaddress()
declare void @llvm.localescape(...)
declare ptr @llvm.localrecover(ptr, ptr, i32)

@IsolationAwarePrivateT_SqbjaYRiRY = common global i32 0, align 4

; Check that the MCSymbol objects are created to be used in "\01?fin$0@0@test2@@".
define void @test2() #0 {
entry:
  %fActivateActCtxSuccess = alloca i32, align 4
  %proc = alloca i32, align 4
  %ulpCookie = alloca i32, align 4
  call void (...) @llvm.localescape(ptr nonnull %fActivateActCtxSuccess, ptr nonnull %proc, ptr nonnull %ulpCookie)
  %tmp0 = tail call ptr @llvm.localaddress()
  call fastcc void @"\01?fin$0@0@test2@@"(ptr %tmp0)
  ret void
; CHECK-LABEL: test2:
; CHECK:	Ltest2$frame_escape_0 = 8
; CHECK:	Ltest2$frame_escape_1 = 4
; CHECK:	Ltest2$frame_escape_2 = 0
; CHECK:	calll "?fin$0@0@test2@@"
}

; Check that the LEA optimization pass works with MCSymbol address displacements.
define internal fastcc void @"\01?fin$0@0@test2@@"(ptr readonly %frame_pointer) unnamed_addr noinline nounwind optsize {
entry:
  %tmp0 = tail call ptr @llvm.localrecover(ptr @test2, ptr %frame_pointer, i32 1)
  %tmp1 = tail call ptr @llvm.localrecover(ptr @test2, ptr %frame_pointer, i32 2)
  %tmp2 = load i32, ptr @IsolationAwarePrivateT_SqbjaYRiRY, align 4
  %tobool = icmp eq i32 %tmp2, 0
  br i1 %tobool, label %if.end, label %land.lhs.true

land.lhs.true:
  %tmp3 = tail call ptr @llvm.localrecover(ptr @test2, ptr %frame_pointer, i32 0)
  %tmp4 = load i32, ptr %tmp3, align 4
  %tobool1 = icmp eq i32 %tmp4, 0
  br i1 %tobool1, label %if.end, label %if.then

if.then:
  %tmp5 = load i32, ptr %tmp0, align 4
  %tobool2 = icmp eq i32 %tmp5, 0
  br i1 %tobool2, label %cond.end, label %cond.true

cond.true:
  %call = tail call i32 @GetLastError()
  br label %cond.end

cond.end:
  %tmp6 = load i32, ptr %tmp1, align 4
  tail call void @IsolationAwareDeactivateActCtx(i32 0, i32 %tmp6)
  br label %if.end

if.end:
  ret void
; CHECK-LABEL: "?fin$0@0@test2@@":
; CHECK:	cmpl $0, Ltest2$frame_escape_0([[REG1:%[a-z]+]])
; CHECK:	leal Ltest2$frame_escape_1([[REG1]]), [[REG2:%[a-z]+]]
; CHECK:	leal Ltest2$frame_escape_2([[REG1]]), [[REG3:%[a-z]+]]
; CHECK:	cmpl $0, ([[REG2]])
; CHECK:	pushl ([[REG3]])
}

attributes #0 = { nounwind optsize "disable-tail-calls"="false" "less-precise-fpmad"="false" "frame-pointer"="none" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+pclmul,+popcnt,+sse,+sse2,+sse3,+sse4.1,+sse4.2,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
