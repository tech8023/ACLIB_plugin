#ifndef ACLIB_PLUGIN_GRAPHICS_HPP
#define ACLIB_PLUGIN_GRAPHICS_HPP

#include "AC.hpp"
#include "Memory.hpp"

#include <Python.h>

namespace ACLIB
{
    struct Graphics
    {
        PyObject_HEAD
        Memory<AC::Graphics> m_graphics;
    };

    static PyObject* _new_(PyTypeObject* type, PyObject* args, PyObject* kwds);
    static void      _del_(PyTypeObject* self);

    extern PyMemberDef  GraphicsType_members[];
    extern PyMethodDef  GraphicsType_methods[];
    extern PyTypeObject GraphicsType;
}  // namespace ACLIB

#endif  // ACLIB_PLUGIN_GRAPHICS_HPP
