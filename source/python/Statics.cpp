#include "Statics.hpp"

#include <structmember.h>

namespace ACLIB
{
    PyObject* _new_(PyTypeObject* type, PyObject* args, PyObject* kwds)
    {
        Statics* self;
        self = reinterpret_cast<Statics*>(type->tp_alloc(type, 0));

        if(self != nullptr)
        {
            self->m_statics = Memory<AC::Statics>("Local\\acpmf_static");
        }
        return reinterpret_cast<PyObject*>(self);
    }

    void _del_(PyTypeObject* self)
    {
        self->tp_free(self);
    }

    PyMemberDef StaticsType_members[] = {
        // {"name", T_FLOAT, offsetof(ACLIB::struct, name), 0, "doc"},
        {nullptr}};

    PyMethodDef StaticsType_methods[] = {
        // {"func_name", (PyCFunction)func, METH_NOARGS, "doc"},
        {nullptr}};

    static PyObject* get_smVersion(Statics* self, void* closure)
    {
        return PyUnicode_FromWideChar(self->m_statics->smVersion, sizeOfArray(self->m_statics->smVersion));
    }
    static PyObject* get_acVersion(Statics* self, void* closure)
    {
        return PyUnicode_FromWideChar(self->m_statics->acVersion, sizeOfArray(self->m_statics->acVersion));
    }
    static PyObject* get_numberOfSessions(Statics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->numberOfSessions);
    }
    static PyObject* get_numCars(Statics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->numCars);
    }
    static PyObject* get_carModel(Statics* self, void* closure)
    {
        return PyUnicode_FromWideChar(self->m_statics->carModel, sizeOfArray(self->m_statics->carModel));
    }
    static PyObject* get_track(Statics* self, void* closure)
    {
        return PyUnicode_FromWideChar(self->m_statics->track, sizeOfArray(self->m_statics->track));
    }
    static PyObject* get_playerName(Statics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->playerName,
            sizeOfArray(self->m_statics->playerName));
    }
    static PyObject* get_playerSurname(Statics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->smVersion,
            sizeOfArray(self->m_statics->playerSurname));
    }
    static PyObject* get_playerNick(Statics* self, void* closure)
    {
        return PyUnicode_FromWideChar(
            self->m_statics->playerNick,
            sizeOfArray(self->m_statics->playerNick));
    }
    static PyObject* get_sectorCount(Statics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->sectorCount);
    }
    static PyObject* get_maxTorque(Statics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->maxTorque);
    }
    static PyObject* get_maxPower(Statics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->maxPower);
    }
    static PyObject* get_maxRpm(Statics* self, void* closure)
    {
        return PyLong_FromLong(self->m_statics->maxRpm);
    }
    static PyObject* get_maxFuel(Statics* self, void* closure)
    {
        return PyFloat_FromDouble(self->m_statics->maxFuel);
    }
    static PyObject* get_suspensionMaxTravel(Statics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_statics->suspensionMaxTravel[0],
            self->m_statics->suspensionMaxTravel[1],
            self->m_statics->suspensionMaxTravel[2],
            self->m_statics->suspensionMaxTravel[3]);
    }
    static PyObject* get_tyreRadius(Statics* self, void* closure)
    {
        return Py_BuildValue(
            "[ffff]",
            self->m_statics->tyreRadius[0],
            self->m_statics->tyreRadius[1],
            self->m_statics->tyreRadius[2],
            self->m_statics->tyreRadius[3]);
    }

    static PyGetSetDef StaticsType_getset[] = {
        {"smVersion", (getter)get_smVersion, nullptr, "", nullptr},
        {"acVersion", (getter)get_acVersion, nullptr, "", nullptr},
        {"numberOfSessions", (getter)get_numberOfSessions, nullptr, "", nullptr},
        {"numCars", (getter)get_numCars, nullptr, "", nullptr},
        {"carModel", (getter)get_carModel, nullptr, "", nullptr},
        {"track", (getter)get_track, nullptr, "", nullptr},
        {"playerName", (getter)get_playerName, nullptr, "", nullptr},
        {"playerSurname", (getter)get_playerSurname, nullptr, "", nullptr},
        {"playerNick", (getter)get_playerNick, nullptr, "", nullptr},
        {"sectorCount", (getter)get_sectorCount, nullptr, "", nullptr},
        {"maxTorque", (getter)get_maxTorque, nullptr, "", nullptr},
        {"maxPower", (getter)get_maxPower, nullptr, "", nullptr},
        {"maxRpm", (getter)get_maxRpm, nullptr, "", nullptr},
        {"maxFuel", (getter)get_maxFuel, nullptr, "", nullptr},
        {"suspensionMaxTravel", (getter)get_suspensionMaxTravel, nullptr, "", nullptr},
        {"tyreRadius", (getter)get_tyreRadius, nullptr, "", nullptr},
        {nullptr}};

    PyTypeObject StaticsType = {
        PyVarObject_HEAD_INIT(&PyType_Type, 0) "aclib.Statics", /* tp_name */
        sizeof(ACLIB::Statics),                                 /* tp_basicsize */
        0,                                                      /* tp_itemsize */
        (destructor)ACLIB::_del_,                               /* tp_dealloc */
        0,                                                      /* tp_print */
        nullptr,                                                /* tp_getattr */
        nullptr,                                                /* tp_setattr */
        nullptr,                                                /* tp_reserved */
        nullptr,                                                /* tp_repr */
        nullptr,                                                /* tp_as_number */
        nullptr,                                                /* tp_as_sequence */
        nullptr,                                                /* tp_as_mapping */
        nullptr,                                                /* tp_hash */
        nullptr,                                                /* tp_call */
        nullptr,                                                /* tp_str */
        nullptr,                                                /* tp_getattro */
        nullptr,                                                /* tp_setattro */
        nullptr,                                                /* tp_as_buffer */
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,                /* tp_flags */
        nullptr,                                                /* tp_doc */
        nullptr,                                                /* tp_traverse */
        nullptr,                                                /* tp_clear */
        nullptr,                                                /* tp_richcompare */
        0,                                                      /* tp_weaklistoffset */
        nullptr,                                                /* tp_iter */
        nullptr,                                                /* tp_iternext */
        StaticsType_methods,                                    /* tp_methods */
        StaticsType_members,                                    /* tp_members */
        StaticsType_getset,                                     /* tp_getset */
        nullptr,                                                /* tp_base */
        nullptr,                                                /* tp_dict */
        nullptr,                                                /* tp_descr_get */
        nullptr,                                                /* tp_descr_set */
        0,                                                      /* tp_dictoffset */
        nullptr,                                                /* tp_init */
        nullptr,                                                /* tp_alloc */
        (newfunc)ACLIB::_new_,                                  /* tp_new */
    };
}  // namespace ACLIB
