cmake_minimum_required(VERSION 3.26)
project(graph_algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(graph_algorithms main.c++
        include/graph.h++
        include/breadth-first_search.h++)
