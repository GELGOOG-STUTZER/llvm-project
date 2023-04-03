#ifndef LLVM_LIB_TARGET_MARCH_MCTARGETDESC_MARCHINFO_H
#define LLVM_LIB_TARGET_MARCH_MCTARGETDESC_MARCHINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace MARCHCC {
enum CondCode {
  EQ,
  NE,
  LE,
  GT,
  LEU,
  GTU,
  INVALID,
};

CondCode getOppositeBranchCondition(CondCode);

enum BRCondCode {
  BREQ = 0x0,
};
} // end namespace MARCHCC

namespace MARCHOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
  OPERAND_UIMM16,
};
} // namespace MARCHOp

} // end namespace llvm

#endif
