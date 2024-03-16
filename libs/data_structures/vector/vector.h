#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// Возвращает структуру-дескриптор вектор из n значений
vector vector_create(size_t n);

// Изменяет количество памяти, выделенное под хранение элементов вектора
void vector_reserve(vector *v, size_t newCapacity);

// Удаляет элементы из контейнера, но не освобождает выделенную память
void vector_clear(vector *v);

// Освобождает память, выделенную под неиспользуемые элементы
void vector_shrinkToFit(vector *v);

// Освобождает память, выделенную вектору
void vector_delete(vector *v);

// Функции проверки на то, является ли вектор пустым
bool vector_isEmpty(vector *v);

// Функции проверки на то, является ли вектор полным
bool vector_isFull(vector *v);

// Возвращает i-ый элемент вектора v
int vector_get_value(vector *v, size_t i);

//добавляет элемент x в конец вектора v. Если вектор заполнен, увеличивает
// количество выделенной ему памяти в 2 раза, используя reserve
void vector_pushBack(vector *v, int x);

// Удаляет последний элемент из вектора
void vector_popBack(vector *v);

// Возвращает указатель на index-ый элемент вектора
int* vector_at(vector *v, size_t index);

// Возвращает указатель на последний элемент вектора
int* vector_back(vector *v);

// Возвращает указатель на нулевой элемент вектора
int* vector_front(vector *v);