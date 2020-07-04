cmake_minimum_required(VERSION 3.2)
project(junk_cpp)

include(CTest)
enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(opt)
add_subdirectory(std)
