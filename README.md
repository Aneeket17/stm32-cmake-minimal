# Minimal STM32 CMAKE Project

This project is for setting up a minimal flashable stm32 project.

# Steps followed for creation of the project

Created src/main.c, cmake/arm-none-eabi-gcc.cmake, CMakeLists.txt initially

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

## Add the linker script
linker/STM32F411xx_FLASH.ld

## Add startup file
src/startup_stm32F411xx.c

Run:
rm -rf build

cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="C:/Aniket/embedded_sys/stm32/projects/stm32_cmake_minimal/cmake/arm-none-eabi-gcc.cmake"

cmake --build build

## Flashing

Use openocd for flashing the code on my STMs2F411RE Nucleo board, which has ST-
LINK

Run:
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program build/firmware.elf verify reset exit"

A successful flash has something like this in the output:
** Programming Started **
** Programming Finished **
** Verify Started **
** Verified OK **
** Resetting Target **
shutdown command invoked

## Debugging

Use the -DCMAKE_BUILD_TYPE=Debug option with the cmake configuration command.
Then build using cmake.

[Debugging the flashed code](docs/images/debug_session_success.png)

## Working Application

Write register-level code to configure GPIO registers and then toggle the on-board LED connceted to PA5.

Include the new .c file in CMakeLists.txt.