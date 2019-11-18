cythonize -i great_module.pyx

运行
gcc main.cpp great_module.c -o main -fPIC -I/home/basic/anaconda3/include/python3.7m  -lpython3.7m -lm

./main