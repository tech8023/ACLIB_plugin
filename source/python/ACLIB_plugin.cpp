#include "ACLIB_plugin.hpp"

#include "Graphics.hpp"
#include "Physics.hpp"
#include "Statics.hpp"

namespace ACLIB
{
    static PyMethodDef module_methods[] = {
        // {"func name", func, METH_NOARGS, "doc"},
        {nullptr, nullptr, 0, nullptr}};

    struct PyModuleDef aclib_module = {
        PyModuleDef_HEAD_INIT,
        "aclib",
        "Assetto Corsa 'all in one' python module that provides an interface for shared memory "
        "pages.",
        -1,
        module_methods};

    PyMODINIT_FUNC PyInit_aclib()
    {
        PyObject* module = PyModule_Create(&aclib_module);

        if(PyType_Ready(&PhysicsType) < 0)
        {
            // err
            printf("Could not init Physics type");
        }

        if(PyType_Ready(&GraphicsType) < 0)
        {
            // err
            printf("Could not init Graphics type");
        }

        if(PyType_Ready(&StaticsType) < 0)
        {
            // err
            printf("Could not init Statics type");
        }

        if(!module)
        {
            // err
            printf("Could not init aclib module.");
        }

        PyModule_AddObject(module, "Physics", reinterpret_cast<PyObject*>(&PhysicsType));
        PyModule_AddObject(module, "Graphics", reinterpret_cast<PyObject*>(&GraphicsType));
        PyModule_AddObject(module, "Statics", reinterpret_cast<PyObject*>(&StaticsType));

        return module;
    }

}  // namespace ACLIB
