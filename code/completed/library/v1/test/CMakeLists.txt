cmake_minimum_required(VERSION 3.20)
project(library_v1_test)

add_executable(${PROJECT_NAME} TestBook.cpp
        TestMember.cpp
        TestUtils.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE library_v1_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE library_data)
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)
