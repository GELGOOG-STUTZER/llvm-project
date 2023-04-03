#ifndef LLVM_LIB_TARGET_MARCH_MARCHTARGETSTREAMER_H
#define LLVM_LIB_TARGET_MARCH_MARCHTARGETSTREAMER_H

#include "llvm/MC/MCStreamer.h"

namespace llvm {

class MARCHTargetStreamer : public MCTargetStreamer {
public:
  MARCHTargetStreamer(MCStreamer &S);
  ~MARCHTargetStreamer() override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MARCH_MARCHTARGETSTREAMER_H