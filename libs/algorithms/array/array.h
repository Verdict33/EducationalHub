#ifndef INC_ARRAY_H
#define INC_ARRAY_H

#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>

// ввод массива data размера n
void array_input(int *a, size_t n);

// вывод массива data размера n
void array_output(const int *a, size_t n);

// возвращает значение первого вхождения элемента x
// в массиве a размера n при его наличии, иначе - n
size_t array_linearSearch(const int *a, const size_t n, int x);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - SIZE_MAX
size_t array_binarySearch(const int *a, const size_t n, int x);

// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает n
size_t array_binarySearchMoreOrEqual(const int *a, const size_t n, int x);

// вставка элемента со значением value
// в массив data размера n на позицию pos
void array_insert(int *a, size_t *n, size_t pos, int value);

// добавление элемента value в конец массива data размера n
void array_append(int *a, size_t *n, int value);

// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void array_deleteByPosSaveOrder(int *a, size_t *n, size_t pos);

// удаление из массива data размера n элемента на позиции pos
// без сохранения порядка оставшихся элементов
// размер массива data уменьшается на единицу
void array_deleteByPosUnsaveOrder(int *a, size_t *n, size_t pos);

// возвращает значение ’истина’ если все элементы
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int array_all(const int *a, size_t n, int (*predicate )(int));

// возвращает значение ’истина’ если хотя бы один элемент
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int array_any(const int *a, size_t n, int (*predicate )(int));

// применяет функцию predicate ко всем элементам массива source
// размера n и сохраняет результат в массиве dest размера n
void array_forEach(const int *source, int *dest, size_t n, const int (*
predicate )(int));

// возвращает количество элементов массива data размера n
// удовлетворяющих функции-предикату predicate
int array_countIf(const int *a, size_t n, int (*predicate )(int));

// удаляет из массива data размера n все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива
void array_deleteIf(int *a, size_t *n, int (*deletePredicate )(int));

//сравнивает элементы, оно вернёт значение больше нуля если первое число больше второго,
// отрицательное если второе число больше первого и вернёт 0 если они равны
int array_compare_ints(const void *a, const void *b);

// Если все элементы массива уникальны выводит 1, иначе 0
bool array_elements_areUnigue(int *a, int n);

//Выводит количество уникальных элементов в массиве
int array_count_unique_element(int *a, int n);

//Возвращает количество value в массиве
int array_count_values(const int *a, int n, int value);
#endif
