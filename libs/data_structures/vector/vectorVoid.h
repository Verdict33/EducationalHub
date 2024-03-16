#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H
#include <limits.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <memory.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
                        // например, если вектор хранит int -
                        // то поле baseTypeSize = sizeof(int)
                        // если вектор хранит float -
                        // то поле baseTypeSize = sizeof(float)
} vectorVoid;

// Возвращает структуру-дескриптор вектор из n значений, с типом данных baseTypeSize
vectorVoid vector_void_create(size_t n, size_t baseTypeSize);

// Изменяет количество памяти, выделенное под хранение элементов вектора
void vector_void_reserve(vectorVoid *v, size_t newCapacity);

// Освобождает память, выделенную под неиспользуемые элементы
void vector_void_shrinkToFit(vectorVoid *v);

// Удаляет элементы из контейнера, но не освобождает выделенную память
void vector_void_clear(vectorVoid *v);

// Освобождает память, выделенную вектору
void vector_void_delete(vectorVoid *v);

// Функции проверки на то, является ли вектор пустым
bool vector_void_isEmpty(vectorVoid *v);

// Функции проверки на то, является ли вектор полным
bool vector_void_isFull(vectorVoid *v);

// Записывает по адресу destination index-ый элемент вектора v
void vector_void_get_value(vectorVoid *v, size_t index, void *destination);

// записывает на index-ый элемент вектора v значение, расположенное по адресу source
void vector_void_set_value(vectorVoid *v, size_t index, void *source);

// Удаляет последний элемент из вектора
void vector_void_popBack(vectorVoid *v);

// добавляет элемент x в конец вектора v. Если вектор заполнен, увеличивает
// количество выделенной ему памяти в 2 раза, используя reserve
void vector_void_pushBack(vectorVoid *v, void *source);

#endif
