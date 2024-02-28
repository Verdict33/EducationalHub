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
vectorVoid createVectorVoid(size_t n, size_t baseTypeSize);

// Изменяет количество памяти, выделенное под хранение элементов вектора
void reserveVoid(vectorVoid *v, size_t newCapacity);

// Освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitVoid(vectorVoid *v);

// Удаляет элементы из контейнера, но не освобождает выделенную память
void clearVoid(vectorVoid *v);

// Освобождает память, выделенную вектору
void deleteVectorVoid(vectorVoid *v);

// Функции проверки на то, является ли вектор пустым
bool isEmptyVoid(vectorVoid *v);

// Функции проверки на то, является ли вектор полным
bool isFullVoid(vectorVoid *v);

// Записывает по адресу destination index-ый элемент вектора v
void getVectorValueVoid(vectorVoid *v, size_t index, void *destination);

// записывает на index-ый элемент вектора v значение, расположенное по адресу source
void setVectorValueVoid(vectorVoid *v, size_t index, void *source);

// Удаляет последний элемент из вектора
void popBackVoid(vectorVoid *v);

// добавляет элемент x в конец вектора v. Если вектор заполнен, увеличивает
// количество выделенной ему памяти в 2 раза, используя reserve
void pushBackVoid(vectorVoid *v, void *source);

#endif
