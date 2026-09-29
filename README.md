# Minimal STM32 CMAKE Project

This project is for sstting up a minimal flashable stm32 project

# Steps followed for creation of the project

Create src/main.c, cmake/arm-none-eabi-gcc.cmake, CMakeLists.txt initially

## Configure project

Run:
cmake -S . -B build `
  -G Ninja `
  -DCMAKE_MAKE_PROGRAM="C:/msys64/ucrt64/bin/ninja.exe" `
  -DCMAKE_TOOLCHAIN_FILE="C:/Aniket/embedded_sys/stm32/projects/stm32_cmake_minimal/cmake/arm-none-eabi-gcc.cmake"

The important options are:
-S . tells CMake where the source tree is.
-B build tells CMake where to place generated build files.
-G Ninja selects Ninja as the build backend.
-DCMAKE_TOOLCHAIN_FILE=... tells CMake to use the Arm cross-compilation setup.
If configuration succeeds, CMake has found the compiler and generated the build files.

## Build the project

Run:
cmake --build build
