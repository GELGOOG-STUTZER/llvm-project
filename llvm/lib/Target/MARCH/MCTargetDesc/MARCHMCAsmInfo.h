#ifndef LLVM_LIB_TARGET_MARCH_MCTARGETDESC_MARCHMCASMINFO_H
#define LLVM_LIB_TARGET_MARCH_MCTARGETDESC_MARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class MARCHMCAsmInfo : public MCAsmInfoELF {
  void anchor() override;

public:
  explicit MARCHMCAsmInfo(const Triple &TT);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MARCH_MCTARGETDESC_MARCHMCASMINFO_H
