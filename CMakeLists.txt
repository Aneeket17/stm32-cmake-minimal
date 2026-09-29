cmake_minimum_required(VERSION 3.25)

project(stm32_cmake_minimal LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(firmware_objects OBJECT
    src/main.c
)

target_compile_options(firmware_objects PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -ffunction-sections
    -fdata-sections
    -Wall
    -Wextra
    -Wpedantic
)

target_compile_definitions(firmware_objects PRIVATE
    STM32F411xx
)