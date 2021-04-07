# ACLIB_plugin

Increases performance of [ACLIB](https://github.com/styinx/ACLIB) by calling the Python C-API instead of computing 
everything in Python.

> Work in progress.

# Build

Python 3.3 which is used by Assetto Corsa requires modules to be built with msvc++ 10.0.

## Via CMake

> mkdir build
> cd build
> cmake ..

## Via Python

> python setup.py build_ext --inplace