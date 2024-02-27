#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

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

// Функции проверки на то, является ли вектор пустым
bool isEmpty(vector *v);

// Функции проверки на то, является ли вектор полным
bool isFull(vector *v);

// Возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v. Если вектор заполнен, увеличивает
// количество выделенной ему памяти в 2 раза, используя reserve
void pushBack(vector *v, int x);

// Удаляет последний элемент из вектора
void popBack(vector *v);

// Возвращает указатель на index-ый элемент вектора
int* atVector(vector *v, size_t index);

// Возвращает указатель на последний элемент вектора
int* back(vector *v);

// Возвращает указатель на нулевой элемент вектора
int* front(vector *v);