//===-- mARCH.h - Top-level interface for mARCH representation ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM mARCH back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_mARCH_mARCH_H
#define LLVM_LIB_TARGET_mARCH_mARCH_H

#include "MCTargetDesc/mARCHMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class mARCHTargetMachine;
  class FunctionPass;

} // end namespace llvm;

#endif