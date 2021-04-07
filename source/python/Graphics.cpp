#include "Graphics.hpp"

#include <structmember.h>

namespace ACLIB
{
    PyObject* _new_(PyTypeObject* type, PyObject* args, PyObject* kwds)
    {
        Graphics* self;
        self = reinterpret_cast<Graphics*>(type->tp_alloc(type, 0));

        if(self != nullptr)
        {
            self->m_graphics = Memory<AC::Graphics>("Local\\acpmf_graphics");
        }
        return reinterpret_cast<PyObject*>(self);
    }

    void _del_(PyTypeObject* self)
    {
        self->tp_free(self);
    }

    PyMemberDef GraphicsType_members[] = {
        // {"name", T_FLOAT, offsetof(ACLIB::struct, name), 0, "doc"},
        {nullptr}};

    PyMethodDef GraphicsType_methods[] = {
        // {"func_name", (PyCFunction)func, METH_NOARGS, "doc"},
        {nullptr}};

    static PyObject* get_packetId(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->packetId);
    }

    static PyObject* get_status(Graphics* self, void* closure)
    {
        return PyLong_FromLong(static_cast<AC::Uint32>(self->m_graphics->status));
    }
    static PyObject* get_session(Graphics* self, void* closure)
    {
        return PyLong_FromLong(static_cast<AC::Uint32>(self->m_graphics->session));
    }
    static PyObject* get_currentTime(Graphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->currentTime,
            sizeOfArray(self->m_graphics->currentTime));
    }
    static PyObject* get_lastTime(Graphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->lastTime,
            sizeOfArray(self->m_graphics->lastTime));
    }
    static PyObject* get_bestTime(Graphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->bestTime,
            sizeOfArray(self->m_graphics->bestTime));
    }
    static PyObject* get_split(Graphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->split,
            sizeOfArray(self->m_graphics->split));
    }
    static PyObject* get_completedLaps(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->completedLaps);
    }
    static PyObject* get_position(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->position);
    }
    static PyObject* get_iCurrentTime(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->iCurrentTime);
    }
    static PyObject* get_iLastTime(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->iLastTime);
    }
    static PyObject* get_iBestTime(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->iBestTime);
    }
    static PyObject* get_sessionTimeLeft(Graphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->sessionTimeLeft);
    }
    static PyObject* get_distanceTraveled(Graphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->distanceTraveled);
    }
    static PyObject* get_isInPit(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->isInPit);
    }
    static PyObject* get_currentSectorIndex(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->currentSectorIndex);
    }
    static PyObject* get_lastSectorTime(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->lastSectorTime);
    }
    static PyObject* get_numberOfLaps(Graphics* self, void* closure)
    {
        return PyLong_FromLong(self->m_graphics->numberOfLaps);
    }
    static PyObject* get_tyreCompound(Graphics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_graphics->tyreCompound,
            sizeOfArray(self->m_graphics->tyreCompound));
    }
    static PyObject* get_replayTimeMultiplier(Graphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->replayTimeMultiplier);
    }
    static PyObject* get_normalizedCarPosition(Graphics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_graphics->normalizedCarPosition);
    }
    static PyObject* get_carCoordinates(Graphics* self, void* closure)
    {
        return Py_BuildValue(
            "[fff]",
            self->m_graphics->carCoordinates[0],
            self->m_graphics->carCoordinates[1],
            self->m_graphics->carCoordinates[2]);
    }

    static PyGetSetDef GraphicsType_getset[] = {
        {"packetId", (getter)get_packetId, nullptr, "", nullptr},
        {"status", (getter)get_status, nullptr, "", nullptr},
        {"session", (getter)get_session, nullptr, "", nullptr},
        {"currentTime", (getter)get_currentTime, nullptr, "", nullptr},
        {"lastTime", (getter)get_lastTime, nullptr, "", nullptr},
        {"bestTime", (getter)get_bestTime, nullptr, "", nullptr},
        {"split", (getter)get_split, nullptr, "", nullptr},
        {"completedLaps", (getter)get_completedLaps, nullptr, "", nullptr},
        {"position", (getter)get_position, nullptr, "", nullptr},
        {"iCurrentTime", (getter)get_iCurrentTime, nullptr, "", nullptr},
        {"iLastTime", (getter)get_iLastTime, nullptr, "", nullptr},
        {"iBestTime", (getter)get_iBestTime, nullptr, "", nullptr},
        {"sessionTimeLeft", (getter)get_sessionTimeLeft, nullptr, "", nullptr},
        {"distanceTraveled", (getter)get_distanceTraveled, nullptr, "", nullptr},
        {"isInPit", (getter)get_isInPit, nullptr, "", nullptr},
        {"currentSectorIndex", (getter)get_currentSectorIndex, nullptr, "", nullptr},
        {"lastSectorTime", (getter)get_lastSectorTime, nullptr, "", nullptr},
        {"numberOfLaps", (getter)get_numberOfLaps, nullptr, "", nullptr},
        {"tyreCompound", (getter)get_tyreCompound, nullptr, "", nullptr},
        {"replayTimeMultiplier", (getter)get_replayTimeMultiplier, nullptr, "", nullptr},
        {"normalizedCarPosition", (getter)get_normalizedCarPosition, nullptr, "", nullptr},
        {"carCoordinates", (getter)get_carCoordinates, nullptr, "", nullptr},
        {nullptr}};

    PyTypeObject GraphicsType = {
        PyVarObject_HEAD_INIT(&PyType_Type, 0) "aclib.Graphics", /* tp_name */
        sizeof(ACLIB::Graphics),                                 /* tp_basicsize */
        0,                                                       /* tp_itemsize */
        (destructor)ACLIB::_del_,                                /* tp_dealloc */
        0,                                                       /* tp_print */
        nullptr,                                                 /* tp_getattr */
        nullptr,                                                 /* tp_setattr */
        nullptr,                                                 /* tp_reserved */
        nullptr,                                                 /* tp_repr */
        nullptr,                                                 /* tp_as_number */
        nullptr,                                                 /* tp_as_sequence */
        nullptr,                                                 /* tp_as_mapping */
        nullptr,                                                 /* tp_hash */
        nullptr,                                                 /* tp_call */
        nullptr,                                                 /* tp_str */
        nullptr,                                                 /* tp_getattro */
        nullptr,                                                 /* tp_setattro */
        nullptr,                                                 /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,                 /* tp_flags */
        nullptr,                                                 /* tp_doc */
        nullptr,                                                 /* tp_traverse */
        nullptr,                                                 /* tp_clear */
        nullptr,                                                 /* tp_richcompare */
        0,                                                       /* tp_weaklistoffset */
        nullptr,                                                 /* tp_iter */
        nullptr,                                                 /* tp_iternext */
        GraphicsType_methods,                                    /* tp_methods */
        GraphicsType_members,                                    /* tp_members */
        GraphicsType_getset,                                     /* tp_getset */
        nullptr,                                                 /* tp_base */
        nullptr,                                                 /* tp_dict */
        nullptr,                                                 /* tp_descr_get */
        nullptr,                                                 /* tp_descr_set */
        0,                                                       /* tp_dictoffset */
        nullptr,                                                 /* tp_init */
        nullptr,                                                 /* tp_alloc */
        (newfunc)ACLIB::_new_,                                   /* tp_new */
    };
}  // namespace ACLIB
