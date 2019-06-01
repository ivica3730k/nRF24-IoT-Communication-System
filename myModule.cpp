//myModule.c//

#include <Python.h>
#include <iostream>
using namespace std;
#include "payloads.h"

static PyObject* castString(PyObject* self, PyObject* args) {
    char *data;

    if (!PyArg_ParseTuple(args, "si", &data)) {
        return NULL;
    }
    return Py_BuildValue("s",data);
    /*
    payload bload;
    bload.datatype = type;

    for (int i = 0; i < data.length(); i++) {
        bload.data[i] = data[i];
    }

    if (type == is_char) return Py_BuildValue("s#",castTo_char(bload));
    else if (type == is_char16_t) return Py_BuildValue("s#",castTo_char16_t(bload));
    else if (type == is_char32_t) return Py_BuildValue("s#",castTo_char32_t(bload));
    else if (type == is_int8_t) return Py_BuildValue("i",castTo_int8_t(bload));
    else if (type == is_int16_t) return Py_BuildValue("l",castTo_int16_t(bload));
    else if (type == is_int32_t) return Py_BuildValue("l",castTo_int32_t(bload));
    else if (type == is_int64_t) return Py_BuildValue("l",castTo_int64_t(bload));
    else if (type == is_uint8_t) return Py_BuildValue("i",castTo_uint8_t(bload));
    else if (type == is_uint16_t) return Py_BuildValue("l",castTo_uint16_t(bload));
    else if (type == is_uint32_t) return Py_BuildValue("l",castTo_uint32_t(bload));
    else if (type == is_uint64_t) return Py_BuildValue("l",castTo_uint16_t(bload));
    else if (type == is_float) return Py_BuildValue("f",castTo_float(bload));
    else if (type == is_double) return Py_BuildValue("d",castTo_float(bload));
    else{
        return NULL;
    }
*/
}

static PyObject* version(PyObject* self)
{
    return Py_BuildValue("s", "Version 1.0");
}

static PyMethodDef myMethods[] = {
        {"castString", castString, METH_VARARGS, "Calculate the Fibonacci numbers."},
        {"version", (PyCFunction)version, METH_NOARGS, "Returns the version."},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef myModule = {
        PyModuleDef_HEAD_INIT,
        "myModule",
        "Casting module for nRF24 Communication system",
        -1,
        myMethods
};

PyMODINIT_FUNC PyInit_myModule(void)
{
    return PyModule_Create(&myModule);
}
