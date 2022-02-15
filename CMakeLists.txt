cmake_minimum_required(VERSION 3.17)
project(Delete_BinTree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,2000")


add_executable(Delete_BinTree main.cpp)