#include <stdio.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// Возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// Изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);

// Удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v);

// Освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

// Освобождает память, выделенную вектору
void deleteVector(vector *v);