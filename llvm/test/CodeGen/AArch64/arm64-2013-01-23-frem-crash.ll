; RUN: llc < %s -mtriple=arm64-eabi
; Make sure we are not crashing on this test.

define void @autogen_SD13158(i1 %arg) {
entry:
  %B26 = frem float 0.000000e+00, poison
  br i1 %arg, label %CF, label %CF77

CF:                                               ; preds = %CF, %CF76
  store float %B26, ptr poison
  br i1 %arg, label %CF, label %CF77

CF77:                                             ; preds = %CF
  ret void
}
