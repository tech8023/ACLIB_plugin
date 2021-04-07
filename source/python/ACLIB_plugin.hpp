#ifndef ACLIB_PLUGIN_ACLIB_PLUGIN_HPP
#define ACLIB_PLUGIN_ACLIB_PLUGIN_HPP

#include <Python.h>

namespace ACLIB
{
    PyMODINIT_FUNC PyInit_aclib();

    extern struct PyModuleDef aclib_module;
}  // namespace ACLIB

#endif  // ACLIB_PLUGIN_ACLIB_PLUGIN_HPP
