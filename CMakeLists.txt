cmake_minimum_required(VERSION 3.0.0)
project(tekmovanje VERSION 0.1.0)

add_executable(tekmovanje "main.cpp")

target_compile_definitions(tekmovanje PRIVATE LOCAL)

set(COMPILER_FLAGS "-std=c++17 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")
