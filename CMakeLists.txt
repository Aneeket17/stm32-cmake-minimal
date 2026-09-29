cmake_minimum_required(VERSION 3.25)

project(stm32_cmake_minimal LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# add_library(firmware_objects OBJECT
#     src/main.c
# )
add_executable(firmware
    src/startup_stm32F411xx.c
    src/main.c
)

target_compile_options(firmware PRIVATE
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

target_compile_definitions(firmware PRIVATE
    STM32F411xx
)

target_link_options(firmware PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -T${CMAKE_SOURCE_DIR}/linker/STM32F411xx_FLASH.ld
    -Wl,--gc-sections
    -Wl,-Map=${CMAKE_BINARY_DIR}/firmware.map
)

add_custom_command(TARGET firmware POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:firmware>
)