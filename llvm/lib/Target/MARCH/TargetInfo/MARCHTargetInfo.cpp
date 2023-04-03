#include "MARCH.h"
#include "llvm/IR/Module.h"
#include "TargetInfo/MARCHTargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheMARCHTarget() {
  static Target TheMARCHTarget;
  return TheMARCHTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMARCHTargetInfo() {
  RegisterTarget<Triple::march, false> X(getTheMARCHTarget(), "MARCH", "MARCH (32-bit MARCH)", "MARCH");
}
