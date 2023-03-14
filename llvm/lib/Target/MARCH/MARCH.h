//===-- MARCH.h - Top-level interface for MARCH representation ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM MARCH back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_MARCH_MARCH_H
#define LLVM_LIB_TARGET_MARCH_MARCH_H

#include "MCTargetDesc/MARCHMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class MARCHTargetMachine;
  class FunctionPass;

} // end namespace llvm;

#endif