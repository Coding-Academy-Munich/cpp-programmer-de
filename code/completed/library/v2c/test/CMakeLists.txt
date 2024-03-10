cmake_minimum_required(VERSION 3.20)
project(library_v2c_test)

add_executable(${PROJECT_NAME} TestBook.cpp
        TestMember.cpp
        TestUtils.cpp
        TestLibrary.cpp
        TestCatalog.cpp
        TestBookCatalog.cpp
        TestMemberCatalog.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE library_v2c_lib)
target_link_libraries(${PROJECT_NAME} PRIVATE library_data)
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)
