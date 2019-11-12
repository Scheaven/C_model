本例是C或者C++调用pyhton的方法

great_module.pyx  文件是python和C的桥接文件

这其中有非Python关键字cdef和public。这些关键字属于Cython。由于我们需要在C语言中使用“编译好的Python代码”，所以得让great_function从外面变得可见，方法就是以“public”修饰。而cdef类似于Python的def，只有使用cdef才可以使用Cython的关键字public。这个函数中其他的部分与正常的Python代码是一样的。接下来
编译 cython great_module.pyx


得到great_module.h和great_module.c。

lib文件下为正常的python函数文件（需用编译器生成__init__.py,否则无法找到文件）

在Windows下编译命令为 cl main.c great_module.c -IC:\Python27\include C:\Python27\libs\python27.lib
在Linux下编译命令为 gcc main.c great_module.c -o main -I/usr/include/python2.7/ -lpython2.7
main.cpp是c++的编译文件
命令直接改为
g++ main.cpp great_module.c -o main -I/usr/include/python2.7/ -lpython2.7

编译后运行命令：

PYTHONPATH=".:$PYTHONPATH" ./main 


参考链接：
https://www.zhihu.com/question/23003213/answer/56121859

http://www.ojit.com/article/96215