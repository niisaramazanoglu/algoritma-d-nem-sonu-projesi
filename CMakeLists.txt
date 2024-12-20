cmake_minimum_required(VERSION 3.29)
project(untitled51 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled51 main.c)
file(COPY words.txt DESTINATION ${CMAKE_BINARY_DIR})




