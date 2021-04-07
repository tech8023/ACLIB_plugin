#ifndef ACLIB_PLUGIN_PHYSICS_HPP
#define ACLIB_PLUGIN_PHYSICS_HPP

#include "AC.hpp"
#include "Memory.hpp"

#include <Python.h>

namespace ACLIB
{
    struct Physics
    {
        PyObject_HEAD
        Memory<AC::Physics> m_physics;
    };

    static PyObject* _new_(PyTypeObject* type, PyObject* args, PyObject* kwds);
    static void      _del_(PyTypeObject* self);

    extern PyMemberDef  PhysicsType_members[];
    extern PyMethodDef  PhysicsType_methods[];
    extern PyTypeObject PhysicsType;
}  // namespace ACLIB

#endif  // ACLIB_PLUGIN_PHYSICS_HPP
