cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(graph_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)


#set(Python3_ROOT_DIR "./venv")

#execute_process(
#        #        OUTPUT venv.stamp
#        #        DEPENDS venv requirements.txt
#        #        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/requirements.txt requirements.txt
#        COMMAND ./venv/Scripts/pip install -r requirements.txt --upgrade
#)







add_executable(example src/example.c++
        include/alg.h++
        include/OrientedGraph.h++
        include/UnorientedGraph.h++
)
add_executable(ex src/ex.c++
        include/setCover.h++
        include/Truba.h++)



add_executable(graph_algorithms main.c++
        include/graph.h++
        include/breadth-first_search.h++
)

#add_executable(example main.c++
#        include/graph.h++
#        include/breadth-first_search.h++
#)


#add_executable(pareto include/pareto.h++ include/backpack.h++ include/item.h++)
#target_link_libraries(example PRIVATE matplotlib_cpp)
#set_target_properties(example PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
