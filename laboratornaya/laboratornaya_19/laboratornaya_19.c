#include "laboratornaya_19.h"

void convert_matrix_rows_to_columns(const char *input_fname, const char *output_fname) {
    FILE *input = fopen(input_fname, "r");
    FILE *output = fopen(output_fname, "w");

    if (input == NULL || output == NULL) {

        printf("Error: Don`t open file.\n");
        return;
    }

    int matrix_order;

    while (fscanf(input, "%d", &matrix_order) == 1) {
        int matrix[matrix_order][matrix_order];

        for (int i = 0; i < matrix_order; ++i) {
            for (int j = 0; j < matrix_order; ++j) {
                if (fscanf(input, "%d", &matrix[i][j]) != 1) {

                    printf("Error: Don`t read matrix element.\n");
                    return;
                }
            }
        }

        fprintf(output, "%d\n", matrix_order);

        for (int i = 0; i < matrix_order; ++i) {
            for (int j = 0; j < matrix_order; ++j) {

                fprintf(output, "%d ", matrix[j][i]);
            }

            fprintf(output, "\n");
        }
    }

    fclose(input);
    fclose(output);
}

void convert_to_floating_point(FILE *input_fname, FILE *output_fname) {
    double number;

    while (fscanf(input_fname, "%lf", &number) == 1) {
        fprintf(output_fname, "%.2f\n", number);
    }
}


void filter_word_by_sample(FILE *input_fname, FILE *output_fname, const char *content) {
    char line[256];

    while (fgets(line, sizeof(line), input_fname) != NULL) {

        line[strcspn(line, "\n")] = 0;

        char *word = strtok(line, " ");
        int is_found_word = 0;

        while (word != NULL) {
            if (strstr(word, content)) {

                fprintf(output_fname, "%s ", word);
                is_found_word = 1;
            }

            word = strtok(NULL, " ");
        }

        if (is_found_word) {
            fprintf(output_fname, "\n");
        }
    }
}

void output_longest_word(FILE* input_fname, FILE* output_fname) {
    char line[100];

    while (fgets(line, 100, input_fname) != NULL) {

        char* word = strtok(line, " ");

        char* longestWord = word;

        size_t biggestLength = strlen(longestWord);

        word = strtok(NULL, " ");

        while (word != NULL) {

            size_t length = strlen(word);

            if (length > biggestLength) {
                longestWord = word;
                biggestLength = length;
            }

            word = strtok(NULL, " ");
        }

        fprintf(output_fname, "%s\n", longestWord);
    }
}

