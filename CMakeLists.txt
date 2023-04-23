cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(flashprint C CXX ASM)
set(CMAKE_C STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(coplight
    coplight.c
)
pico_enable_stdio_usb(coplight 1)
pico_enable_stdio_uart(coplight 0)
pico_add_extra_outputs(coplight)
target_include_directories(coplight PRIVATE ${CMAKE_CURRENT_LIST_DIR} )
target_link_libraries(coplight pico_cyw43_arch_lwip_threadsafe_background pico_stdlib)
