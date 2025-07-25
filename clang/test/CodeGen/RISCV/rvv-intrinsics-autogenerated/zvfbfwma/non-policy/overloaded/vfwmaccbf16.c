// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +zve64x \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwmaccbf16_vv_f32mf2(
// CHECK-RV64-SAME: <vscale x 1 x float> [[VD:%.*]], <vscale x 1 x bfloat> [[VS1:%.*]], <vscale x 1 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwmaccbf16.nxv1f32.nxv1bf16.nxv1bf16.i64(<vscale x 1 x float> [[VD]], <vscale x 1 x bfloat> [[VS1]], <vscale x 1 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwmaccbf16_vv_f32mf2(vfloat32mf2_t vd, vbfloat16mf4_t vs1,
                                         vbfloat16mf4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwmaccbf16_vf_f32mf2(
// CHECK-RV64-SAME: <vscale x 1 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 1 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwmaccbf16.nxv1f32.bf16.nxv1bf16.i64(<vscale x 1 x float> [[VD]], bfloat [[VS1]], <vscale x 1 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwmaccbf16_vf_f32mf2(vfloat32mf2_t vd, __bf16 vs1,
                                         vbfloat16mf4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwmaccbf16_vv_f32m1(
// CHECK-RV64-SAME: <vscale x 2 x float> [[VD:%.*]], <vscale x 2 x bfloat> [[VS1:%.*]], <vscale x 2 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwmaccbf16.nxv2f32.nxv2bf16.nxv2bf16.i64(<vscale x 2 x float> [[VD]], <vscale x 2 x bfloat> [[VS1]], <vscale x 2 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwmaccbf16_vv_f32m1(vfloat32m1_t vd, vbfloat16mf2_t vs1,
                                       vbfloat16mf2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwmaccbf16_vf_f32m1(
// CHECK-RV64-SAME: <vscale x 2 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 2 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwmaccbf16.nxv2f32.bf16.nxv2bf16.i64(<vscale x 2 x float> [[VD]], bfloat [[VS1]], <vscale x 2 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwmaccbf16_vf_f32m1(vfloat32m1_t vd, __bf16 vs1,
                                       vbfloat16mf2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwmaccbf16_vv_f32m2(
// CHECK-RV64-SAME: <vscale x 4 x float> [[VD:%.*]], <vscale x 4 x bfloat> [[VS1:%.*]], <vscale x 4 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwmaccbf16.nxv4f32.nxv4bf16.nxv4bf16.i64(<vscale x 4 x float> [[VD]], <vscale x 4 x bfloat> [[VS1]], <vscale x 4 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwmaccbf16_vv_f32m2(vfloat32m2_t vd, vbfloat16m1_t vs1,
                                       vbfloat16m1_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwmaccbf16_vf_f32m2(
// CHECK-RV64-SAME: <vscale x 4 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 4 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwmaccbf16.nxv4f32.bf16.nxv4bf16.i64(<vscale x 4 x float> [[VD]], bfloat [[VS1]], <vscale x 4 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwmaccbf16_vf_f32m2(vfloat32m2_t vd, __bf16 vs1,
                                       vbfloat16m1_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwmaccbf16_vv_f32m4(
// CHECK-RV64-SAME: <vscale x 8 x float> [[VD:%.*]], <vscale x 8 x bfloat> [[VS1:%.*]], <vscale x 8 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwmaccbf16.nxv8f32.nxv8bf16.nxv8bf16.i64(<vscale x 8 x float> [[VD]], <vscale x 8 x bfloat> [[VS1]], <vscale x 8 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwmaccbf16_vv_f32m4(vfloat32m4_t vd, vbfloat16m2_t vs1,
                                       vbfloat16m2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwmaccbf16_vf_f32m4(
// CHECK-RV64-SAME: <vscale x 8 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 8 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwmaccbf16.nxv8f32.bf16.nxv8bf16.i64(<vscale x 8 x float> [[VD]], bfloat [[VS1]], <vscale x 8 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwmaccbf16_vf_f32m4(vfloat32m4_t vd, __bf16 vs1,
                                       vbfloat16m2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwmaccbf16_vv_f32m8(
// CHECK-RV64-SAME: <vscale x 16 x float> [[VD:%.*]], <vscale x 16 x bfloat> [[VS1:%.*]], <vscale x 16 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwmaccbf16.nxv16f32.nxv16bf16.nxv16bf16.i64(<vscale x 16 x float> [[VD]], <vscale x 16 x bfloat> [[VS1]], <vscale x 16 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwmaccbf16_vv_f32m8(vfloat32m8_t vd, vbfloat16m4_t vs1,
                                       vbfloat16m4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwmaccbf16_vf_f32m8(
// CHECK-RV64-SAME: <vscale x 16 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 16 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwmaccbf16.nxv16f32.bf16.nxv16bf16.i64(<vscale x 16 x float> [[VD]], bfloat [[VS1]], <vscale x 16 x bfloat> [[VS2]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwmaccbf16_vf_f32m8(vfloat32m8_t vd, __bf16 vs1,
                                       vbfloat16m4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwmaccbf16_vv_f32mf2_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], <vscale x 1 x float> [[VD:%.*]], <vscale x 1 x bfloat> [[VS1:%.*]], <vscale x 1 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwmaccbf16.mask.nxv1f32.nxv1bf16.nxv1bf16.i64(<vscale x 1 x float> [[VD]], <vscale x 1 x bfloat> [[VS1]], <vscale x 1 x bfloat> [[VS2]], <vscale x 1 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwmaccbf16_vv_f32mf2_m(vbool64_t vm, vfloat32mf2_t vd,
                                           vbfloat16mf4_t vs1,
                                           vbfloat16mf4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwmaccbf16_vf_f32mf2_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], <vscale x 1 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 1 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwmaccbf16.mask.nxv1f32.bf16.nxv1bf16.i64(<vscale x 1 x float> [[VD]], bfloat [[VS1]], <vscale x 1 x bfloat> [[VS2]], <vscale x 1 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwmaccbf16_vf_f32mf2_m(vbool64_t vm, vfloat32mf2_t vd,
                                           __bf16 vs1, vbfloat16mf4_t vs2,
                                           size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwmaccbf16_vv_f32m1_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], <vscale x 2 x float> [[VD:%.*]], <vscale x 2 x bfloat> [[VS1:%.*]], <vscale x 2 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwmaccbf16.mask.nxv2f32.nxv2bf16.nxv2bf16.i64(<vscale x 2 x float> [[VD]], <vscale x 2 x bfloat> [[VS1]], <vscale x 2 x bfloat> [[VS2]], <vscale x 2 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwmaccbf16_vv_f32m1_m(vbool32_t vm, vfloat32m1_t vd,
                                         vbfloat16mf2_t vs1, vbfloat16mf2_t vs2,
                                         size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwmaccbf16_vf_f32m1_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], <vscale x 2 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 2 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwmaccbf16.mask.nxv2f32.bf16.nxv2bf16.i64(<vscale x 2 x float> [[VD]], bfloat [[VS1]], <vscale x 2 x bfloat> [[VS2]], <vscale x 2 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwmaccbf16_vf_f32m1_m(vbool32_t vm, vfloat32m1_t vd,
                                         __bf16 vs1, vbfloat16mf2_t vs2,
                                         size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwmaccbf16_vv_f32m2_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], <vscale x 4 x float> [[VD:%.*]], <vscale x 4 x bfloat> [[VS1:%.*]], <vscale x 4 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwmaccbf16.mask.nxv4f32.nxv4bf16.nxv4bf16.i64(<vscale x 4 x float> [[VD]], <vscale x 4 x bfloat> [[VS1]], <vscale x 4 x bfloat> [[VS2]], <vscale x 4 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwmaccbf16_vv_f32m2_m(vbool16_t vm, vfloat32m2_t vd,
                                         vbfloat16m1_t vs1, vbfloat16m1_t vs2,
                                         size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwmaccbf16_vf_f32m2_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], <vscale x 4 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 4 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwmaccbf16.mask.nxv4f32.bf16.nxv4bf16.i64(<vscale x 4 x float> [[VD]], bfloat [[VS1]], <vscale x 4 x bfloat> [[VS2]], <vscale x 4 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwmaccbf16_vf_f32m2_m(vbool16_t vm, vfloat32m2_t vd,
                                         __bf16 vs1, vbfloat16m1_t vs2,
                                         size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwmaccbf16_vv_f32m4_m(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], <vscale x 8 x float> [[VD:%.*]], <vscale x 8 x bfloat> [[VS1:%.*]], <vscale x 8 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwmaccbf16.mask.nxv8f32.nxv8bf16.nxv8bf16.i64(<vscale x 8 x float> [[VD]], <vscale x 8 x bfloat> [[VS1]], <vscale x 8 x bfloat> [[VS2]], <vscale x 8 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwmaccbf16_vv_f32m4_m(vbool8_t vm, vfloat32m4_t vd,
                                         vbfloat16m2_t vs1, vbfloat16m2_t vs2,
                                         size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwmaccbf16_vf_f32m4_m(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], <vscale x 8 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 8 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwmaccbf16.mask.nxv8f32.bf16.nxv8bf16.i64(<vscale x 8 x float> [[VD]], bfloat [[VS1]], <vscale x 8 x bfloat> [[VS2]], <vscale x 8 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwmaccbf16_vf_f32m4_m(vbool8_t vm, vfloat32m4_t vd,
                                         __bf16 vs1, vbfloat16m2_t vs2,
                                         size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwmaccbf16_vv_f32m8_m(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], <vscale x 16 x float> [[VD:%.*]], <vscale x 16 x bfloat> [[VS1:%.*]], <vscale x 16 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwmaccbf16.mask.nxv16f32.nxv16bf16.nxv16bf16.i64(<vscale x 16 x float> [[VD]], <vscale x 16 x bfloat> [[VS1]], <vscale x 16 x bfloat> [[VS2]], <vscale x 16 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwmaccbf16_vv_f32m8_m(vbool4_t vm, vfloat32m8_t vd,
                                         vbfloat16m4_t vs1, vbfloat16m4_t vs2,
                                         size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwmaccbf16_vf_f32m8_m(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], <vscale x 16 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 16 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwmaccbf16.mask.nxv16f32.bf16.nxv16bf16.i64(<vscale x 16 x float> [[VD]], bfloat [[VS1]], <vscale x 16 x bfloat> [[VS2]], <vscale x 16 x i1> [[VM]], i64 7, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwmaccbf16_vf_f32m8_m(vbool4_t vm, vfloat32m8_t vd,
                                         __bf16 vs1, vbfloat16m4_t vs2,
                                         size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwmaccbf16_vv_f32mf2_rm(
// CHECK-RV64-SAME: <vscale x 1 x float> [[VD:%.*]], <vscale x 1 x bfloat> [[VS1:%.*]], <vscale x 1 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwmaccbf16.nxv1f32.nxv1bf16.nxv1bf16.i64(<vscale x 1 x float> [[VD]], <vscale x 1 x bfloat> [[VS1]], <vscale x 1 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwmaccbf16_vv_f32mf2_rm(vfloat32mf2_t vd,
                                            vbfloat16mf4_t vs1,
                                            vbfloat16mf4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwmaccbf16_vf_f32mf2_rm(
// CHECK-RV64-SAME: <vscale x 1 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 1 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwmaccbf16.nxv1f32.bf16.nxv1bf16.i64(<vscale x 1 x float> [[VD]], bfloat [[VS1]], <vscale x 1 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwmaccbf16_vf_f32mf2_rm(vfloat32mf2_t vd, __bf16 vs1,
                                            vbfloat16mf4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwmaccbf16_vv_f32m1_rm(
// CHECK-RV64-SAME: <vscale x 2 x float> [[VD:%.*]], <vscale x 2 x bfloat> [[VS1:%.*]], <vscale x 2 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwmaccbf16.nxv2f32.nxv2bf16.nxv2bf16.i64(<vscale x 2 x float> [[VD]], <vscale x 2 x bfloat> [[VS1]], <vscale x 2 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwmaccbf16_vv_f32m1_rm(vfloat32m1_t vd, vbfloat16mf2_t vs1,
                                          vbfloat16mf2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwmaccbf16_vf_f32m1_rm(
// CHECK-RV64-SAME: <vscale x 2 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 2 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwmaccbf16.nxv2f32.bf16.nxv2bf16.i64(<vscale x 2 x float> [[VD]], bfloat [[VS1]], <vscale x 2 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwmaccbf16_vf_f32m1_rm(vfloat32m1_t vd, __bf16 vs1,
                                          vbfloat16mf2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwmaccbf16_vv_f32m2_rm(
// CHECK-RV64-SAME: <vscale x 4 x float> [[VD:%.*]], <vscale x 4 x bfloat> [[VS1:%.*]], <vscale x 4 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwmaccbf16.nxv4f32.nxv4bf16.nxv4bf16.i64(<vscale x 4 x float> [[VD]], <vscale x 4 x bfloat> [[VS1]], <vscale x 4 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwmaccbf16_vv_f32m2_rm(vfloat32m2_t vd, vbfloat16m1_t vs1,
                                          vbfloat16m1_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwmaccbf16_vf_f32m2_rm(
// CHECK-RV64-SAME: <vscale x 4 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 4 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwmaccbf16.nxv4f32.bf16.nxv4bf16.i64(<vscale x 4 x float> [[VD]], bfloat [[VS1]], <vscale x 4 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwmaccbf16_vf_f32m2_rm(vfloat32m2_t vd, __bf16 vs1,
                                          vbfloat16m1_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwmaccbf16_vv_f32m4_rm(
// CHECK-RV64-SAME: <vscale x 8 x float> [[VD:%.*]], <vscale x 8 x bfloat> [[VS1:%.*]], <vscale x 8 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwmaccbf16.nxv8f32.nxv8bf16.nxv8bf16.i64(<vscale x 8 x float> [[VD]], <vscale x 8 x bfloat> [[VS1]], <vscale x 8 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwmaccbf16_vv_f32m4_rm(vfloat32m4_t vd, vbfloat16m2_t vs1,
                                          vbfloat16m2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwmaccbf16_vf_f32m4_rm(
// CHECK-RV64-SAME: <vscale x 8 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 8 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwmaccbf16.nxv8f32.bf16.nxv8bf16.i64(<vscale x 8 x float> [[VD]], bfloat [[VS1]], <vscale x 8 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwmaccbf16_vf_f32m4_rm(vfloat32m4_t vd, __bf16 vs1,
                                          vbfloat16m2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwmaccbf16_vv_f32m8_rm(
// CHECK-RV64-SAME: <vscale x 16 x float> [[VD:%.*]], <vscale x 16 x bfloat> [[VS1:%.*]], <vscale x 16 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwmaccbf16.nxv16f32.nxv16bf16.nxv16bf16.i64(<vscale x 16 x float> [[VD]], <vscale x 16 x bfloat> [[VS1]], <vscale x 16 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwmaccbf16_vv_f32m8_rm(vfloat32m8_t vd, vbfloat16m4_t vs1,
                                          vbfloat16m4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwmaccbf16_vf_f32m8_rm(
// CHECK-RV64-SAME: <vscale x 16 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 16 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwmaccbf16.nxv16f32.bf16.nxv16bf16.i64(<vscale x 16 x float> [[VD]], bfloat [[VS1]], <vscale x 16 x bfloat> [[VS2]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwmaccbf16_vf_f32m8_rm(vfloat32m8_t vd, __bf16 vs1,
                                          vbfloat16m4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwmaccbf16_vv_f32mf2_rm_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], <vscale x 1 x float> [[VD:%.*]], <vscale x 1 x bfloat> [[VS1:%.*]], <vscale x 1 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwmaccbf16.mask.nxv1f32.nxv1bf16.nxv1bf16.i64(<vscale x 1 x float> [[VD]], <vscale x 1 x bfloat> [[VS1]], <vscale x 1 x bfloat> [[VS2]], <vscale x 1 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwmaccbf16_vv_f32mf2_rm_m(vbool64_t vm, vfloat32mf2_t vd,
                                              vbfloat16mf4_t vs1,
                                              vbfloat16mf4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwmaccbf16_vf_f32mf2_rm_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], <vscale x 1 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 1 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwmaccbf16.mask.nxv1f32.bf16.nxv1bf16.i64(<vscale x 1 x float> [[VD]], bfloat [[VS1]], <vscale x 1 x bfloat> [[VS2]], <vscale x 1 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwmaccbf16_vf_f32mf2_rm_m(vbool64_t vm, vfloat32mf2_t vd,
                                              __bf16 vs1, vbfloat16mf4_t vs2,
                                              size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwmaccbf16_vv_f32m1_rm_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], <vscale x 2 x float> [[VD:%.*]], <vscale x 2 x bfloat> [[VS1:%.*]], <vscale x 2 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwmaccbf16.mask.nxv2f32.nxv2bf16.nxv2bf16.i64(<vscale x 2 x float> [[VD]], <vscale x 2 x bfloat> [[VS1]], <vscale x 2 x bfloat> [[VS2]], <vscale x 2 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwmaccbf16_vv_f32m1_rm_m(vbool32_t vm, vfloat32m1_t vd,
                                            vbfloat16mf2_t vs1,
                                            vbfloat16mf2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwmaccbf16_vf_f32m1_rm_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], <vscale x 2 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 2 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwmaccbf16.mask.nxv2f32.bf16.nxv2bf16.i64(<vscale x 2 x float> [[VD]], bfloat [[VS1]], <vscale x 2 x bfloat> [[VS2]], <vscale x 2 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwmaccbf16_vf_f32m1_rm_m(vbool32_t vm, vfloat32m1_t vd,
                                            __bf16 vs1, vbfloat16mf2_t vs2,
                                            size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwmaccbf16_vv_f32m2_rm_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], <vscale x 4 x float> [[VD:%.*]], <vscale x 4 x bfloat> [[VS1:%.*]], <vscale x 4 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwmaccbf16.mask.nxv4f32.nxv4bf16.nxv4bf16.i64(<vscale x 4 x float> [[VD]], <vscale x 4 x bfloat> [[VS1]], <vscale x 4 x bfloat> [[VS2]], <vscale x 4 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwmaccbf16_vv_f32m2_rm_m(vbool16_t vm, vfloat32m2_t vd,
                                            vbfloat16m1_t vs1,
                                            vbfloat16m1_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwmaccbf16_vf_f32m2_rm_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], <vscale x 4 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 4 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwmaccbf16.mask.nxv4f32.bf16.nxv4bf16.i64(<vscale x 4 x float> [[VD]], bfloat [[VS1]], <vscale x 4 x bfloat> [[VS2]], <vscale x 4 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwmaccbf16_vf_f32m2_rm_m(vbool16_t vm, vfloat32m2_t vd,
                                            __bf16 vs1, vbfloat16m1_t vs2,
                                            size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwmaccbf16_vv_f32m4_rm_m(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], <vscale x 8 x float> [[VD:%.*]], <vscale x 8 x bfloat> [[VS1:%.*]], <vscale x 8 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwmaccbf16.mask.nxv8f32.nxv8bf16.nxv8bf16.i64(<vscale x 8 x float> [[VD]], <vscale x 8 x bfloat> [[VS1]], <vscale x 8 x bfloat> [[VS2]], <vscale x 8 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwmaccbf16_vv_f32m4_rm_m(vbool8_t vm, vfloat32m4_t vd,
                                            vbfloat16m2_t vs1,
                                            vbfloat16m2_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwmaccbf16_vf_f32m4_rm_m(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], <vscale x 8 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 8 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwmaccbf16.mask.nxv8f32.bf16.nxv8bf16.i64(<vscale x 8 x float> [[VD]], bfloat [[VS1]], <vscale x 8 x bfloat> [[VS2]], <vscale x 8 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwmaccbf16_vf_f32m4_rm_m(vbool8_t vm, vfloat32m4_t vd,
                                            __bf16 vs1, vbfloat16m2_t vs2,
                                            size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwmaccbf16_vv_f32m8_rm_m(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], <vscale x 16 x float> [[VD:%.*]], <vscale x 16 x bfloat> [[VS1:%.*]], <vscale x 16 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwmaccbf16.mask.nxv16f32.nxv16bf16.nxv16bf16.i64(<vscale x 16 x float> [[VD]], <vscale x 16 x bfloat> [[VS1]], <vscale x 16 x bfloat> [[VS2]], <vscale x 16 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwmaccbf16_vv_f32m8_rm_m(vbool4_t vm, vfloat32m8_t vd,
                                            vbfloat16m4_t vs1,
                                            vbfloat16m4_t vs2, size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwmaccbf16_vf_f32m8_rm_m(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], <vscale x 16 x float> [[VD:%.*]], bfloat noundef [[VS1:%.*]], <vscale x 16 x bfloat> [[VS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwmaccbf16.mask.nxv16f32.bf16.nxv16bf16.i64(<vscale x 16 x float> [[VD]], bfloat [[VS1]], <vscale x 16 x bfloat> [[VS2]], <vscale x 16 x i1> [[VM]], i64 0, i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwmaccbf16_vf_f32m8_rm_m(vbool4_t vm, vfloat32m8_t vd,
                                            __bf16 vs1, vbfloat16m4_t vs2,
                                            size_t vl) {
  return __riscv_vfwmaccbf16(vm, vd, vs1, vs2, __RISCV_FRM_RNE, vl);
}
