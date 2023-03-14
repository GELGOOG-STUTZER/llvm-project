add_llvm_component_group(mArch)

set(LLVM_TARGET_DEFINITIONS mARCH.td)

# Generate mARCHGenRegisterInfo.inc and mARCHGenInstrInfo.inc which included by
#  your hand code C++ files.
# mARCHGenRegisterInfo.inc came from mARCHRegisterInfo.td, mARCHGenInstrInfo.inc
#  came from mARCHInstrInfo.td.
tablegen(LLVM mARCHGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM mARCHGenInstrInfo.inc -gen-instr-info)

# mARCHCommonTableGen must be defined
add_public_tablegen_target(mARCHCommonTableGen)

# mARCHCodeGen should match with LLVMBuild.txt mARCHCodeGen
add_llvm_target(mARCHCodeGen
  mARCHTargetMachine.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  Core
  MC
  mARCHDesc
  mARCHInfo
  SelectionDAG
  Support
  Target
  GlobalISel

  ADD_TO_COMPONENT
  mARCH
  )

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)