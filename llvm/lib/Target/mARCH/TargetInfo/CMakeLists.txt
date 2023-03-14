add_llvm_component_library(LLVMmARCHInfo
  mARCHTargetInfo.cpp

  LINK_COMPONENTS
  Support

  ADD_TO_COMPONENT
  mARCH
  )