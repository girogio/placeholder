cmake_minimum_required(VERSION 3.16)
project(task2 C)

set(CMAKE_C_STANDARD 11)

add_library(dt_lib SHARED task2a.c)

add_executable(task2a test_driver_a.c)
#add_executable(task2b task2b.c)

target_link_libraries(task2a dt_lib)


