add_llvm_component_group(MARCH)

set(LLVM_TARGET_DEFINITIONS MARCH.td)

# Generate MARCHGenRegisterInfo.inc and MARCHGenInstrInfo.inc which included by
#  your hand code C++ files.
# MARCHGenRegisterInfo.inc came from MARCHRegisterInfo.td, MARCHGenInstrInfo.inc
#  came from MARCHInstrInfo.td.
tablegen(LLVM MARCHGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MARCHGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MARCHGenCallingConv.inc -gen-callingconv)
tablegen(LLVM MARCHGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM MARCHGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM MARCHGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM MARCHGenDAGISel.inc -gen-dag-isel)

#tablegen(LLVM MARCHGenDisassemblerTables.inc -gen-disassembler)

# MARCHCommonTableGen must be defined
add_public_tablegen_target(MARCHCommonTableGen)

# MARCHCodeGen should match with LLVMBuild.txt MARCHCodeGen
add_llvm_target(MARCHCodeGen
  MARCHAsmPrinter.cpp
  MARCHFrameLowering.cpp
  MARCHInstrInfo.cpp
  MARCHISelDagToDag.cpp
  MARCHISelLowering.cpp
  MARCHMachineFunctionInfo.cpp
  MARCHMCInstLower.cpp
  MARCHRegisterInfo.cpp
  MARCHSubtarget.cpp
  MARCHTargetMachine.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  Core
  MC
  MARCHDesc
  MARCHInfo
  SelectionDAG
  Support
  Target
  GlobalISel

  ADD_TO_COMPONENT
  MARCH
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
