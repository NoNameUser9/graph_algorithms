cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(graph_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)



add_executable(example
        include/alg.h++
        include/OrientedGraph.h++
        include/UnorientedGraph.h++
)

add_executable(ex src/ex.c++
        include/setCover.h++
        include/Truba.h++
        include/deep-first_search.h++
        include/breadth-first_search.h++
)

add_executable(graph_algorithms main.c++
        include/graph.h++
        include/breadth-first_search.h++
)

