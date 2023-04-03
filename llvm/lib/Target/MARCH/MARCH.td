//===----------------------------------------------------------------------===//
// This is the top level entry point for the MARCH target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// MARCH Subtarget features
//===----------------------------------------------------------------------===//

//def FeatureDummy
//    : SubtargetFeature<"dummy", "Dummy", "true",
//                       "Dummy feature">;

//===----------------------------------------------------------------------===//
// Target-dependent interfaces
//===----------------------------------------------------------------------===//

include "MARCHRegisterInfo.td"

//===----------------------------------------------------------------------===//
// Calling Conv, Instruction Descriptions
//===----------------------------------------------------------------------===//

include "MARCHCallingConv.td"

include "MARCHInstrInfo.td"
def MARCHInstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// MARCH processors supported.
//===----------------------------------------------------------------------===//

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;
//def : Proc<"dummy-st", []>;

// Will generate MARCHGenAsmWrite.inc included by MARCHInstPrinter.cpp, contents
//  as follows,
// void MARCHInstPrinter::printInstruction(const MCInst *MI, raw_ostream &O) {...}
// const char *MARCHInstPrinter::getRegisterName(unsigned RegNo) {...}
def MARCH : Target {
  let InstructionSet = MARCHInstrInfo;
}
