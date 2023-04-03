//===----------------------------------------------------------------------===//
//
// Implements the info about MARCH target spec.
//
//===----------------------------------------------------------------------===//

#include "MARCHTargetMachine.h"
#include "MARCH.h"
//#include "MARCHTargetTransformInfo.h"
#include "TargetInfo/MARCHTargetInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Target/TargetOptions.h"

#define DEBUG_TYPE "MARCH"

using namespace llvm;

static Reloc::Model getRelocModel(Optional<Reloc::Model> RM) {
  return RM.getValueOr(Reloc::Static);
}

/// MARCHTargetMachine ctor - Create an ILP32 Architecture model
MARCHTargetMachine::MARCHTargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     Optional<Reloc::Model> RM,
                                     Optional<CodeModel::Model> CM,
                                     CodeGenOpt::Level OL, bool JIT)
    : LLVMTargetMachine(T,
                        "e-m:e-p:32:32-i1:8:32-i8:8:32-i16:16:32-i32:32:32-"
                        "f32:32:32-i64:32-f64:32-a:0:32-n32",
                        TT, CPU, FS, Options, getRelocModel(RM),
                        getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  initAsmInfo();
}

MARCHTargetMachine::~MARCHTargetMachine() = default;

namespace {

/// MARCH Code Generator Pass Configuration Options.
class MARCHPassConfig : public TargetPassConfig {
public:
  MARCHPassConfig(MARCHTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  MARCHTargetMachine &getMARCHTargetMachine() const {
    return getTM<MARCHTargetMachine>();
  }

  bool addInstSelector() override;
  // void addPreEmitPass() override;
  // void addPreRegAlloc() override;
};

} // end anonymous namespace

TargetPassConfig *MARCHTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new MARCHPassConfig(*this, PM);
}

bool MARCHPassConfig::addInstSelector() {
  addPass(createMARCHISelDag(getMARCHTargetMachine(), getOptLevel()));
  return false;
}

// void MARCHPassConfig::addPreEmitPass() { llvm_unreachable(""); }

// void MARCHPassConfig::addPreRegAlloc() { llvm_unreachable(""); }

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMARCHTarget() {
  RegisterTargetMachine<MARCHTargetMachine> X(getTheMARCHTarget());
}

#if 0
TargetTransformInfo
MARCHTargetMachine::getTargetTransformInfo(const Function &F) {
  return TargetTransformInfo(MARCHTTIImpl(this, F));
}
#endif
