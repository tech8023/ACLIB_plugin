#ifndef ACLIB_PLUGIN_STATICS_HPP
#define ACLIB_PLUGIN_STATICS_HPP

#include "AC.hpp"
#include "Memory.hpp"

#include <Python.h>

namespace ACLIB
{
    struct Statics
    {
        PyObject_HEAD
        Memory<AC::Statics> m_statics;
    };

    static PyObject* _new_(PyTypeObject* type, PyObject* args, PyObject* kwds);
    static void      _del_(PyTypeObject* self);

    extern PyMemberDef  StaticsType_members[];
    extern PyMethodDef  StaticsType_methods[];
    extern PyTypeObject StaticsType;
}  // namespace ACLIB

#endif  // ACLIB_PLUGIN_STATICS_HPP
