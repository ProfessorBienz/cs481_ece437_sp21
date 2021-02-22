cmake_minimum_required(VERSION 3.0)
project(hw1)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wredundant-decls -Wcast-align -Wshadow")

enable_testing()

#include(source)

set(hw1_INCDIR ${CMAKE_CURRENT_SOURCE_DIR})

include_directories("external")

#/////////////////////////// star information of google test ///////////////////////////////
set(GOOGLETEST_ROOT external/googletest CACHE STRING "Google Test source root")
include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )
set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )
foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()
add_library(googletest STATIC ${GOOGLETEST_SOURCES})
target_link_libraries(googletest pthread)
#///////////////////////////// end information of google test //////////////////////////////

add_library(hw1 STATIC child_procs.h child_procs.cpp create_procs.h create_procs.cpp
    jobs.h jobs.cpp scheduler.h scheduler.cpp)

add_executable(process_example process_example.cpp)
target_link_libraries(process_example hw1)

add_subdirectory(tests)

