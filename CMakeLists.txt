cmake_minimum_required (VERSION 3.0)

project (Final_Project)

set(HEADER_FILES graph.h Apartment.h) 
add_library(Apartment Apartment.cpp ${HEADER_FILES})
add_executable(main main.cpp ${HEADER_FILES})
target_link_libraries(main Apartment)
target_compile_options(main PRIVATE -std=c++0x -g -Wall)