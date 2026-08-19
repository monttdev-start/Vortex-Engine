cmake_minimum_required(VERSION 4.2)
project(Vortex_Engine)

set(CMAKE_CXX_STANDARD 20)

add_library(Vortex_Engine SHARED library.cpp
        src/vortex-core/input/Validation.cpp
        src/vortex-core/input/Validation.h
)

