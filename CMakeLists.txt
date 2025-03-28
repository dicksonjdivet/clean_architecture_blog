cmake_minimum_required(VERSION 3.5)
project(blog)

add_subdirectory(submodules/CMakeTools)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(submodules/OHTTP)

add_subdirectory(lib)
add_subdirectory(app)

include(import/googletest)
add_subdirectory(test)
