#include "source/python/ACLIB_plugin.hpp"

#include <Python.h>
#include <iostream>

int main(int argc, char** argv)
{
    using namespace ACLIB;

    wchar_t* program = Py_DecodeLocale(argv[0], nullptr);
    if(program == nullptr)
    {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }

    if(PyImport_AppendInittab("aclib", PyInit_aclib) == -1)
    {
        fprintf(stderr, "Error: could not extend in-built modules table\n");
        exit(1);
    }

    Py_SetProgramName(program);
    Py_Initialize();

    const auto module = PyImport_ImportModule("aclib");
    if(!module)
    {
        PyErr_Print();
        fprintf(stderr, "Error: could not import module 'aclib'\n");
    }

    PyMem_RawFree(program);
    return 0;
}
