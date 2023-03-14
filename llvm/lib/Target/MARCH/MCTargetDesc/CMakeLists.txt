add_llvm_component_library(LLVMMARCHDesc
  MARCHMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  MARCHInfo
  Support

  ADD_TO_COMPONENT
  MARCH
  )