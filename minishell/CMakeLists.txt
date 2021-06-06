cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(Google_tests)
include_directories(Google_tests/lib/googletest-master/googletest/include)
include_directories(Google_tests/lib/googletest-master/googlemock/include)
target_link_libraries(NameOfTheProject gtest gtest_main)
add_executable(Google_tests main.c)
