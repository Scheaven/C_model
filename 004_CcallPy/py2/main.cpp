#include <Python.h>
#include "great_module.h"
using namespace std;

int main(int argc, char *argv[]) {
    PyObject *tuple;
    Py_Initialize();
    initgreat_module();
    tuple = Py_BuildValue("[i,s,s]", 2, "hello url1111111","2222222222222");
    printf("%s\n",great_function(
                    tuple                
           ));
    Py_Finalize();
}

// 直接传参
// int main(int argc, char *argv[]) {
//     Py_Initialize();
//     initgreat_module();//init+模型名
//     printf("%s",great_constfun("Hello",2));
//     Py_Finalize();
// }

