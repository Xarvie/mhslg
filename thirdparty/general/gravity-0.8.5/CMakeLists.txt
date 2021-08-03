cmake_minimum_required(VERSION 3.0)
project(gravity VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)

option(BUILD_CLI "Build the command line interface" OFF)
#set(CMAKE_CXX_COMPILER "D:/packet/em/emsdk/upstream/emscripten/em++.bat")
#set(CMAKE_c_COMPILER "D:/packet/em/emsdk/upstream/emscripten/emcc.bat")
# ----------------------------------------------------------------
# Library
add_subdirectory(src)

# ----------------------------------------------------------------
# Command Line Interface
if(BUILD_CLI)
    add_subdirectory(src/cli)
endif()
