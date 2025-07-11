// NOTE: Assertions have been autogenerated by utils/update_mc_test_checks.py UTC_ARGS: --version 5
// RUN: llvm-mc -triple=amdgcn -mcpu=gfx1250 -mattr=+real-true16 -show-encoding < %s | FileCheck --check-prefix=GFX1250 %s

v_lshl_add_u64 v[2:3], s[4:5], v7, v[8:9]
// GFX1250: v_lshl_add_u64 v[2:3], s[4:5], v7, v[8:9] ; encoding: [0x02,0x00,0x52,0xd6,0x04,0x0e,0x22,0x04]

v_lshl_add_u64 v[2:3], v[4:5], 0, 1
// GFX1250: v_lshl_add_u64 v[2:3], v[4:5], 0, 1     ; encoding: [0x02,0x00,0x52,0xd6,0x04,0x01,0x05,0x02]

v_lshl_add_u64 v[2:3], v[4:5], 3, s[2:3]
// GFX1250: v_lshl_add_u64 v[2:3], v[4:5], 3, s[2:3] ; encoding: [0x02,0x00,0x52,0xd6,0x04,0x07,0x09,0x00]

v_lshl_add_u64 v[2:3], s[4:5], 4, v[2:3]
// GFX1250: v_lshl_add_u64 v[2:3], s[4:5], 4, v[2:3] ; encoding: [0x02,0x00,0x52,0xd6,0x04,0x08,0x09,0x04]

v_lshl_add_u64 v[2:3], v[4:5], v7, 12345
// GFX1250: v_lshl_add_u64 v[2:3], v[4:5], v7, 0x3039 ; encoding: [0x02,0x00,0x52,0xd6,0x04,0x0f,0xfe,0x03,0x39,0x30,0x00,0x00]
