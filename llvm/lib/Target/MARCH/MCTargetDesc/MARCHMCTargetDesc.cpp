#include "MARCHMCTargetDesc.h"
#include "TargetInfo/MARCHTargetInfo.h"
#include "MARCHInfo.h"
#include "MARCHInstPrinter.h"
#include "MARCHMCAsmInfo.h"
#include "MARCHTargetStreamer.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#include "MARCHGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "MARCHGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "MARCHGenRegisterInfo.inc"

static MCInstrInfo *createMARCHMCInstrInfo() {
  auto *X = new MCInstrInfo();
  InitMARCHMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createMARCHMCRegisterInfo(const Triple &TT) {
  auto *X = new MCRegisterInfo();
  InitMARCHMCRegisterInfo(X, MARCH::R1);
  return X;
}

static MCSubtargetInfo *createMARCHMCSubtargetInfo(const Triple &TT,
                                                  StringRef CPU, StringRef FS) {
  return createMARCHMCSubtargetInfoImpl(TT, CPU, /*TuneCPU=*/CPU, FS);
}

static MCAsmInfo *createMARCHMCAsmInfo(const MCRegisterInfo &MRI,
                                      const Triple &TT,
                                      const MCTargetOptions &Options) {
  MCAsmInfo *MAI = new MARCHMCAsmInfo(TT);
  MCRegister SP = MRI.getDwarfRegNum(MARCH::R2, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createMARCHMCInstPrinter(const Triple &T,
                                              unsigned SyntaxVariant,
                                              const MCAsmInfo &MAI,
                                              const MCInstrInfo &MII,
                                              const MCRegisterInfo &MRI) {
  return new MARCHInstPrinter(MAI, MII, MRI);
}

MARCHTargetStreamer::MARCHTargetStreamer(MCStreamer &S) : MCTargetStreamer(S) {}
MARCHTargetStreamer::~MARCHTargetStreamer() = default;

static MCTargetStreamer *createTargetAsmStreamer(MCStreamer &S,
                                                 formatted_raw_ostream &OS,
                                                 MCInstPrinter *InstPrint,
                                                 bool isVerboseAsm) {
  return new MARCHTargetStreamer(S);
}

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMARCHTargetMC() {
  // Register the MC asm info.
  Target &TheMARCHTarget = getTheMARCHTarget();
  RegisterMCAsmInfoFn X(TheMARCHTarget, createMARCHMCAsmInfo);

  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheMARCHTarget, createMARCHMCInstrInfo);

  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheMARCHTarget, createMARCHMCRegisterInfo);

  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheMARCHTarget,
                                          createMARCHMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheMARCHTarget, createMARCHMCInstPrinter);

  TargetRegistry::RegisterAsmTargetStreamer(TheMARCHTarget,
                                            createTargetAsmStreamer);
}
