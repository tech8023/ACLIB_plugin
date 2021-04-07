cmake_minimum_required(VERSION 3.17)
project(ACLIB_plugin)

set(CMAKE_CXX_STANDARD 14)

# AC uses python 3.3
# Requires msvc++ 10.0
find_package(PythonLibs 3.3 EXACT REQUIRED)

include_directories(
        source/
        ${PYTHON_INCLUDE_DIRS})

set(SOURCES
        source/AC.hpp
        source/ACLIB.hpp
        source/Memory.cpp
        source/Memory.hpp
        source/python/ACLIB_plugin.cpp
        source/python/ACLIB_plugin.hpp
        source/python/Physics.cpp
        source/python/Physics.hpp
        source/python/Graphics.cpp
        source/python/Graphics.hpp
        source/python/Statics.cpp
        source/python/Statics.hpp)

# The plugin
add_library(ACLIB_plugin
        ${SOURCES}
        ${PYTHON_LIBRARIES})
target_link_libraries(ACLIB_plugin ${PYTHON_LIBRARIES})

# Test application
add_executable(ACLIB_plugin_run main.cpp)
target_link_libraries(ACLIB_plugin_run ACLIB_plugin ${PYTHON_LIBRARIES})