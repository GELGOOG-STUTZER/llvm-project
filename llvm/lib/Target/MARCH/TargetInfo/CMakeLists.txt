add_llvm_component_library(LLVMMARCHInfo
  MARCHTargetInfo.cpp

  LINK_COMPONENTS
  Support

  ADD_TO_COMPONENT
  MARCH
  )
