cmake_minimum_required(VERSION 3.2)
project(junk_cpp)

include(CTest)
enable_testing()

add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(std)
