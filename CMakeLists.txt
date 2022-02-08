cmake_minimum_required(VERSION 3.17)
project(ACLIB_plugin)


set(CMAKE_CXX_STANDARD 11)

# AC uses python 3.3
# Requires msvc++ 10.0
# find_package(PythonLibs 3.3 EXACT REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(
        source/
        ${PYTHON_INCLUDE_DIRS})

set(SOURCES

        source/AC.hpp
        source/ACLIB.hpp
        source/SharedMemory.hpp
        source/EventLoop.cpp
        source/EventLoop.hpp

        source/python/ACLIB_plugin.cpp
        source/python/PyPhysics.cpp
        source/python/PyPhysics.hpp
        source/python/PyGraphics.cpp
        source/python/PyGraphics.hpp
        source/python/PyStatics.cpp
        source/python/PyStatics.hpp
        source/python/PyEventLoop.cpp
        source/python/PyEventLoop.hpp

        source/util/Thread.cpp
        source/util/Thread.hpp)

# The plugin
add_library(ACLIB_plugin
        ${SOURCES}
        ${PYTHON_LIBRARIES})
target_link_libraries(ACLIB_plugin ${PYTHON_LIBRARIES})
