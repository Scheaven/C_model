#include <Python.h>
#include "great_module.h"

int main(int argc, char *argv[]) {
    PyObject *tuple;
    Py_Initialize();
    initgreat_module();
    tuple = Py_BuildValue("[i,s,s]", 2, "hello url1111111","2222222222222");
    printf("%s\n",PyString_AsString(
                great_function(
                    tuple
                )
            ));
    Py_Finalize();
}