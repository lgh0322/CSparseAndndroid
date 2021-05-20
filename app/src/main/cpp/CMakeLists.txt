
cmake_minimum_required(VERSION 3.18.1)


project("vaca")


include_directories(${CMAKE_SOURCE_DIR}/sparse)
file(GLOB_RECURSE sparse_src ${CMAKE_SOURCE_DIR}/*.c)
add_library(sparse ${sparse_src})

add_library(
        vaca-lib
        SHARED
        vaca.cpp
)


find_library(
        log-lib


        log)


target_link_libraries(
        vaca-lib
        sparse
        ${log-lib})