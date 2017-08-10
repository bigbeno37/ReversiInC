cmake_minimum_required(VERSION 3.8)
project(ReversiInC)

file(GLOB SOURCES
    src/*.h
    src/*.c)

set(CMAKE_C_STANDARD 90)

add_executable(ReversiInC ${SOURCES})