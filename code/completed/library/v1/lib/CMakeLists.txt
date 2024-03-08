cmake_minimum_required(VERSION 3.20)
project(library_v1_lib)

add_library(${PROJECT_NAME} Book.cpp Book.h
        Member.cpp
        Member.h
        Utils.h
        Utils.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} PRIVATE library_data)
