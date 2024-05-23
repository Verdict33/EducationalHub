#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "../../libs/data_structures/vector/vector.h"
#include "../../libs/data_structures/string/string.h"

#define MAX_AMOUNT_SPORTSMAN 20

typedef struct sportsman {
    char name[256];
    double best_result;
} sportsman;

// Cчитывает матрицу из файла, после чего конвертирует строки матрицы в столбцы и
// записывает результат обратно в файл.
void convert_matrix_rows_to_columns(const char *input_fname, const char *output_fname);

// Cчитывает вещественные числа с фиксированной точкой из текстового файла, преобразует их в вещественные
// числа с плавающей точкой, сохраняя две цифры после точки в мантиссе, записывает результаты в другой файл.
void convert_to_floating_point(FILE *input_fname, FILE *output_fname);

// Фильтрует слова в текстовом файле, сохраняя только слова,
// которые содержат указанную последовательность символов, записывает их в выходной файл.
void filter_word_by_sample(FILE *input_fname, FILE *output_fname, const char *content);

// Cчитывает строки из входного файла, для каждой строки выводит в выходной файл только самое длинное слово.
void output_longest_word(FILE* input_fname, FILE* output_fname);

// Преобразовывает файл таким образом, чтобы сначала были положительные числа, а затем отрицательные.
// Порядок следования как положительных, так и отрицательных чисел сохряется.
void reorganization_numbers(const char* fname);

// Преобразовывает файл со всеми спортсменами, сохранив в нем информацию только о членах команды.
void get_best_team(const char* fname, const int n);