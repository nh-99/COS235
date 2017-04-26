cmake_minimum_required(VERSION 3.6)
project(TestProject)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES hw4/main.c)
add_executable(TestProject ${SOURCE_FILES})