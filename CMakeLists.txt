cmake_minimum_required(VERSION 4.2)
project(Vortex_Engine)

set(CMAKE_CXX_STANDARD 20)

add_library(Vortex_Engine SHARED
        src/vortex-core/input/Validation.cpp
        src/vortex-core/input/Validation.h
        src/vortex-core/main.cpp
        src/vortex-core/virtualizer/DataVirtualizer.cpp
        src/vortex-core/virtualizer/DataVirtualizer.h
        src/vortex-core/model/Tree.cpp
        src/vortex-core/model/Tree.h
)

target_include_directories(Vortex_Engine PRIVATE src)

