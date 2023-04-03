#ifndef LLVM_LIB_TARGET_MARCH_MARCH_H
#define LLVM_LIB_TARGET_MARCH_MARCH_H

#include "MCTargetDesc/MARCHMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
class MARCHTargetMachine;
class FunctionPass;
class MARCHSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerMARCHMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                    AsmPrinter &AP);
bool LowerMARCHMachineOperandToMCOperand(const MachineOperand &MO,
                                         MCOperand &MCOp, const AsmPrinter &AP);

FunctionPass *createMARCHISelDag(MARCHTargetMachine &TM,
                                CodeGenOpt::Level OptLevel);


namespace MARCH {
enum {
  GP = MARCH::R0,
  RA = MARCH::R1,
  SP = MARCH::R2,
  FP = MARCH::R3,
  BP = MARCH::R4,
};
} // namespace MARCH

} // namespace llvm

#endif
