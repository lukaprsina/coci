cmake_minimum_required(VERSION 3.0.0)
project(coci VERSION 0.1.0)

add_executable(coci dice_combinations.cpp)

target_compile_definitions(coci PRIVATE LOCAL)

set(COMPILER_FLAGS "-std=c++17 -DEVALUATOR -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")
