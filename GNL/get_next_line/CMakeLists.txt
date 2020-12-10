cmake_minimum_required(VERSION 3.17)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(get_next_line
        get_next_line_bonus.c
        get_next_line_bonus.h
        get_next_line_utils_bonus.c
        main_bonus.c)
