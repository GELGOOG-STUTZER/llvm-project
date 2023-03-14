//===-- MARCHTargetInfo.cpp - MARCH Target Implementation -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "MARCH.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target llvm::TheMARCHTarget;

extern "C" void LLVMInitializeMARCHTargetInfo() {
  RegisterTarget<Triple::march,
                 /*HasJIT=*/false>
      X(TheMARCHTarget, "MARCH", "MARCH (32-bit simhulator arch)", "MARCH");
}