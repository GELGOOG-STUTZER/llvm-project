//===-- mARCH.td - Describe the mARCH Target Machine ----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This is the top level entry point for the mARCH target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Target-dependent interfaces
//===----------------------------------------------------------------------===//

include "mARCHRegisterInfo.td"

//===----------------------------------------------------------------------===//
// Calling Conv, Instruction Descriptions
//===----------------------------------------------------------------------===//

include "mARCHInstrInfo.td"
def mARCHInstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// mARCH processors supported.
//===----------------------------------------------------------------------===//

// Will generate mARCHGenAsmWrite.inc included by mARCHInstPrinter.cpp, contents
//  as follows,
// void mARCHInstPrinter::printInstruction(const MCInst *MI, raw_ostream &O) {...}
// const char *mARCHInstPrinter::getRegisterName(unsigned RegNo) {...}
def mARCH : Target {
  let InstructionSet = mARCHInstrInfo;
}