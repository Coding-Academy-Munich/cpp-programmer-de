cmake_minimum_required(VERSION 3.20)
project(library_v2b)

add_subdirectory(lib)
add_subdirectory(test)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE library_data)
target_link_libraries(${PROJECT_NAME} PRIVATE library_v2b_lib)
