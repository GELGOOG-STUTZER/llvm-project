add_llvm_component_library(LLVMmARCHDesc
  mARCHMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  mARCHInfo
  Support

  ADD_TO_COMPONENT
  mARCH
  )