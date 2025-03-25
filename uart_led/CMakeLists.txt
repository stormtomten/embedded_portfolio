cmake_minimum_required(VERSION 3.16)

set(PICO_BOARD pico_w)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(uart_led LANGUAGES C CXX ASM)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)


pico_sdk_init()
add_subdirectory(src)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)



target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_uart
    pico_cyw43_arch_none
)

#pico_add_extra_outputs(${PROJECT_NAME})
