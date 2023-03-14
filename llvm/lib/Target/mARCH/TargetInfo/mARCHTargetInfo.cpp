//===-- mARCHTargetInfo.cpp - mARCH Target Implementation -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "mARCH.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target llvm::ThemARCHTarget;

extern "C" void LLVMInitializemARCHTargetInfo() {
  RegisterTarget<Triple::march,
                 /*HasJIT=*/false>
      X(ThemARCHTarget, "mARCH", "mARCH (32-bit simhulator arch)", "mARCH");
}