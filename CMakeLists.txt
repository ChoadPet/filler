cmake_minimum_required(VERSION 3.7)
project(filler)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES filler.h filler.c)
add_executable(filler ${SOURCE_FILES})
target_link_libraries(filler ${CMAKE_SOURCE_DIR}/libft.a)