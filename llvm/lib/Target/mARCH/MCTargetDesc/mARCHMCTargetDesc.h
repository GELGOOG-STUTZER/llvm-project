//===-- mARCHMCTargetDesc.h - mARCH Target Descriptions -----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides mARCH specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_mARCH_MCTARGETDESC_mARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_mARCH_MCTARGETDESC_mARCHMCTARGETDESC_H

#include "llvm/Support/DataTypes.h"

#include <memory>

namespace llvm {
class Target;
class Triple;

extern Target ThemARCHTarget;

} // End llvm namespace

// Defines symbolic names for mARCH registers.  This defines a mapping from
// register name to register number.
#define GET_REGINFO_ENUM
#include "mARCHGenRegisterInfo.inc"

// Defines symbolic names for the mARCH instructions.
#define GET_INSTRINFO_ENUM
#include "mARCHGenInstrInfo.inc"

#endif