#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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