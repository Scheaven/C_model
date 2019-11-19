#include <Python.h>
#include "great_module.h"
int main(int argc, char *argv[]) {
    PyObject *tuple;
    Py_Initialize();
    PyInit_great_module();
    printf("%s\n","-------------" );
    printf("%s\n", PyBytes_AsString(
        great_function(
            PyBytes_FromString("hello"),
            PyLong_FromLong(1)
        )
    ));
    Py_Finalize();
    system("pause");
    return 0;
}