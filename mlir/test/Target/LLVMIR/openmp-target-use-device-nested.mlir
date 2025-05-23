// RUN: mlir-translate -mlir-to-llvmir %s | FileCheck %s

// This tests check that target code nested inside a target data region which
// has only use_device_ptr mapping corectly generates code on the device pass.

// CHECK:         define weak_odr protected amdgpu_kernel void @__omp_offloading{{.*}}main_
// CHECK-NEXT:       entry:
// CHECK-NEXT:         %[[VAL_3:.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-NEXT:         %[[ASCAST:.*]] = addrspacecast ptr addrspace(5) %[[VAL_3]] to ptr
// CHECK-NEXT:         store ptr %[[VAL_4:.*]], ptr %[[ASCAST]], align 8
// CHECK-NEXT:         %[[VAL_5:.*]] = call i32 @__kmpc_target_init(ptr @__omp_offloading_{{.*}}_kernel_environment, ptr %[[VAL_6:.*]])
// CHECK-NEXT:         %[[VAL_7:.*]] = icmp eq i32 %[[VAL_5]], -1
// CHECK-NEXT:         br i1 %[[VAL_7]], label %[[VAL_8:.*]], label %[[VAL_9:.*]]
// CHECK:            user_code.entry:                                  ; preds = %[[VAL_10:.*]]
// CHECK-NEXT:         %[[VAL_11:.*]] = load ptr, ptr %[[ASCAST]], align 8
// CHECK-NEXT:         br label %[[AFTER_ALLOC:.*]]

// CHECK:            [[AFTER_ALLOC]]:
// CHECK-NEXT:         br label %[[VAL_12:.*]]

// CHECK:            [[VAL_12]]:
// CHECK-NEXT:         br label %[[TARGET_REG_ENTRY:.*]]

// CHECK:            [[TARGET_REG_ENTRY]]:                                       ; preds = %[[VAL_12]]
// CHECK-NEXT:         %[[VAL_13:.*]] = load ptr, ptr %[[VAL_11]], align 8
// CHECK-NEXT:         store i32 999, ptr %[[VAL_13]], align 4
// CHECK-NEXT:         br label %[[VAL_14:.*]]
module attributes {dlti.dl_spec = #dlti.dl_spec<#dlti.dl_entry<"dlti.alloca_memory_space", 5 : ui32>>, llvm.target_triple = "amdgcn-amd-amdhsa", omp.is_target_device = true } {
  llvm.func @_QQmain() attributes {fir.bindc_name = "main"} {
    %0 = llvm.mlir.constant(1 : i64) : i64
    %a = llvm.alloca %0 x !llvm.ptr : (i64) -> !llvm.ptr<5>
    %ascast = llvm.addrspacecast %a : !llvm.ptr<5> to !llvm.ptr
    %map = omp.map.info var_ptr(%ascast : !llvm.ptr, !llvm.ptr)   map_clauses(tofrom) capture(ByRef) -> !llvm.ptr {name = ""}
    omp.target_data use_device_ptr(%map -> %arg0 : !llvm.ptr)  {
      %map1 = omp.map.info var_ptr(%arg0 : !llvm.ptr, !llvm.ptr)   map_clauses(tofrom) capture(ByRef) -> !llvm.ptr {name = ""}
      omp.target map_entries(%map1 -> %arg1 : !llvm.ptr){
        %1 = llvm.mlir.constant(999 : i32) : i32
        %2 = llvm.load %arg1 : !llvm.ptr -> !llvm.ptr
        llvm.store %1, %2 : i32, !llvm.ptr
        omp.terminator
      }
      omp.terminator
    }
    llvm.return
  }
}
