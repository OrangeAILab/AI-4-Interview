cmake_minimum_required(VERSION 3.21)
project(Interviews)

set(CMAKE_CXX_STANDARD 11)

add_executable(Interviews main.cpp backTracing/back_tracing.cpp basic/bacis_algorithm.cpp linkList/link_list.cpp dynamicProgramming/dp.cpp tree/tree.cpp linkList/link_list.h basic/basic_algorithm.h dynamicProgramming/dp.h backTracing/back_tracing.h tree/tree.h mathAlgorithm/math_algorithm.cpp mathAlgorithm/math_algorithm.h stackQueen/stack_queen.cpp stackQueen/stack_queen.h array/array.cpp array/array.h AI/nms.cpp AI/conv2d.cpp)
