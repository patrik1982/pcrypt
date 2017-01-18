project(pcrypt_test)

add_definitions(${GCC_COMPILE_FLAGS} "-std=c++11 -g -O3") # -Werr")
link_directories(/usr/lib/x86_64-linux-gnu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )


add_executable(pcrypt_test
  pcrypt_test.cpp
  Test_Common.cpp
  BlockCipherTest.cpp
  Test_RC6.cpp
  Test_Rijndael.cpp
  Test_Serpent.cpp
  )
target_include_directories(pcrypt PUBLIC .)
target_link_libraries(pcrypt_test pcrypt)
