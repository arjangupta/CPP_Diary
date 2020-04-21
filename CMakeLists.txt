cmake_minimum_required(VERSION 3.9)

project(cpp-diary)

#use C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++11 support enabled by default.")

#add_subdirectory(small_programs)
add_subdirectory(thread_pool)