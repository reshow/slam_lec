#declare the vision of cmake required
cmake_minimum_required(VERSION 2.8)
#declare a cmake project
project (HelloSLAM)
#add a executable program (exe name,sorce code file)
add_executable(helloSLAM helloSLAM.cpp)
add_library(hello libHelloSLAM.cpp)#add_library(hello SHARED libhelloSLAM.cpp)
add_executable(useHello useHello.cpp)
target_link_libraries(useHello hello)
set(CMAKE_BUILD_TYPE "Debug")
