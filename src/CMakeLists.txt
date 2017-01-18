project(pcrypt C ASM)

add_definitions(${GCC_COMPILE_FLAGS} "-std=c++11 -g -msse4.2 -maes -O3") # -Werr")
link_directories(/usr/lib/x86_64-linux-gnu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_library(pcrypt SHARED
  # encryption algorithms
  IBlockCipher.cpp
  IAESCandidate.cpp
  Rijndael.cpp
  Serpent.cpp
  RC6.cpp
  Twofish.cpp
  # block encryption modes
  IBlockCipherMode.cpp
  ECB.cpp
  CBC.cpp
  PCBC.cpp
  CFB.cpp
  OFB.cpp
  # hash algorithms
  )
  
  
  
  

