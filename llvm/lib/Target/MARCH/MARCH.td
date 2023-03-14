//===-- MARCH.td - Describe the MARCH Target Machine ----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This is the top level entry point for the MARCH target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Target-dependent interfaces
//===----------------------------------------------------------------------===//

include "MARCHRegisterInfo.td"

//===----------------------------------------------------------------------===//
// Calling Conv, Instruction Descriptions
//===----------------------------------------------------------------------===//

include "MARCHInstrInfo.td"
def MARCHInstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// MARCH processors supported.
//===----------------------------------------------------------------------===//

// Will generate MARCHGenAsmWrite.inc included by MARCHInstPrinter.cpp, contents
//  as follows,
// void MARCHInstPrinter::printInstruction(const MCInst *MI, raw_ostream &O) {...}
// const char *MARCHInstPrinter::getRegisterName(unsigned RegNo) {...}
def MARCH : Target {
  let InstructionSet = MARCHInstrInfo;
}