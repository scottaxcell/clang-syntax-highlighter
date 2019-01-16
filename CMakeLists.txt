cmake_minimum_required(VERSION 3.9)

project(hello_world)

#include_directories(${PROJECT_SOURCE_DIR})
add_executable(app main.cpp SyntaxHighlighter.cpp)

set(LLVM_PATH /usr/lib/llvm-6.0)
link_directories(${LLVM_PATH}/lib)
include_directories(${LLVM_PATH}/include ${PROJECT_SOURCE_DIR})

#set(LLVM_LIBRARIES_PATH ${LLVM_PATH}/lib)
#set(LIBS
#        ${LLVM_LIBRARIES_PATH}/LLVMSupport.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMCore.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMMC.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMTarget.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMAnalysis.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMipa.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMTransformUtils.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMInstCombine.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMScalarOpts.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMCodeGen.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMExecutionEngine.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMJIT.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMX86Utils.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMX86Info.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMMCParser.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMX86AsmParser.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMX86AsmPrinter.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMAsmPrinter.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMSelectionDAG.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMX86CodeGen.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMX86Disassembler.lib
#        ${LLVM_LIBRARIES_PATH}/LLVMInterpreter.lib
#        )
#
#target_link_libraries(app ${LIBS})