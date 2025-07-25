//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <clc/workitem/clc_get_local_id.h>

_CLC_OVERLOAD _CLC_DEF size_t __clc_get_local_id(uint dim) {
  switch (dim) {
  case 0:
    return __nvvm_read_ptx_sreg_tid_x();
  case 1:
    return __nvvm_read_ptx_sreg_tid_y();
  case 2:
    return __nvvm_read_ptx_sreg_tid_z();
  default:
    return 0;
  }
}
