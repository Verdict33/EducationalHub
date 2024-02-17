#include <stdio.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// Возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);