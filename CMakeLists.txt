cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(graph_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

include(GNUInstallDirs)
set(PACKAGE_NAME matplotlib_cpp)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/${PACKAGE_NAME}/cmake)

set(Python3_ROOT_DIR "./venv")

execute_process(
        #        OUTPUT venv.stamp
        #        DEPENDS venv requirements.txt
        #        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/requirements.txt requirements.txt
        COMMAND ./venv/Scripts/pip install -r requirements.txt --upgrade
)
# Library target
add_library(matplotlib_cpp INTERFACE
        src/example.c++
        main.c++)
target_include_directories(matplotlib_cpp
        INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_compile_features(matplotlib_cpp INTERFACE
        cxx_std_11
)
# TODO: Use `Development.Embed` component when requiring cmake >= 3.18
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
target_link_libraries(matplotlib_cpp INTERFACE
        Python3::Python
        Python3::Module
)
find_package(Python3 COMPONENTS NumPy)
if(Python3_NumPy_FOUND)
    target_link_libraries(matplotlib_cpp INTERFACE
            Python3::NumPy
    )
else()
    target_compile_definitions(matplotlib_cpp INTERFACE WITHOUT_NUMPY)
endif()
install(
        TARGETS matplotlib_cpp
        EXPORT install_targets
)


# Install headers
install(FILES
        "include/matplotlibcpp.h++"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


# Install targets file
install(EXPORT install_targets
        FILE
        ${PACKAGE_NAME}Targets.cmake
        NAMESPACE
        ${PACKAGE_NAME}::
        DESTINATION
        ${INSTALL_CONFIGDIR}
)


# Install matplotlib_cppConfig.cmake
include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PACKAGE_NAME}Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${PACKAGE_NAME}Config.cmake
        INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PACKAGE_NAME}Config.cmake
        DESTINATION ${INSTALL_CONFIGDIR}
)

add_executable(example src/example.c++
        include/alg.h++
        include/OrientedGraph.h++
        include/UnorientedGraph.h++
)
add_executable(ex src/ex.c++
)
# Include Python headers
target_include_directories(ex PRIVATE ${Python3_INCLUDE_DIRS})

# Link Python libraries
target_link_libraries(ex PRIVATE ${Python3_LIBRARIES})
target_link_libraries(example PRIVATE matplotlib_cpp)
set_target_properties(example PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(graph_algorithms main.c++
        include/graph.h++
        include/breadth-first_search.h++
)

#add_executable(example main.c++
#        include/graph.h++
#        include/breadth-first_search.h++
#)

target_link_libraries(graph_algorithms PRIVATE matplotlib_cpp)
set_target_properties(graph_algorithms PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

#add_executable(pareto include/pareto.h++ include/backpack.h++ include/item.h++)
#target_link_libraries(example PRIVATE matplotlib_cpp)
#set_target_properties(example PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
