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

void reorganization_numbers(const char* fname) {
    vector positive_numbers = vector_create(2);
    vector negative_numbers = vector_create(2);

    FILE* file = fopen(fname, "rb");

    if (file == NULL) {
        printf("Error: Don`t read file\n");
        exit(1);
    }

    int current_number;

    while (fread(&current_number, sizeof(int), 1, file) == 1) {
        if (current_number >= 0)
            vector_pushBack(&positive_numbers, current_number);
        else
            vector_pushBack(&negative_numbers, current_number);
    }

    fclose(file);

    file = fopen(fname, "wb");

    if (file == NULL) {
        printf("Error: Don`t read file\n");
        exit(1);
    }

    for (int i = 0; i < positive_numbers.size; i++) {
        fwrite(positive_numbers.data + i, sizeof(int), 1, file);
    }

    for (int i = 0; i < negative_numbers.size; i++) {
        fwrite(negative_numbers.data + i, sizeof(int), 1, file);
    }

    vector_delete(&positive_numbers);
    vector_delete(&negative_numbers);

    fclose(file);
}

void sort_sportsman(sportsman sm[], const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sm[j].best_result < sm[j + 1].best_result) {

                sportsman temp = sm[j];
                sm[j] = sm[j + 1];
                sm[j + 1] = temp;
            }
        }
    }
}

void get_best_team(const char* fname, const int n) {

    FILE* file = fopen(fname, "rb");

    if (file == NULL) {
        printf("Error: Don`t read file\n");
        exit(1);
    }

    sportsman* team = (sportsman*) malloc(MAX_AMOUNT_SPORTSMAN * sizeof(sportsman));

    sportsman* rec = team;

    int amount_sportsman = 0;

    while (fread(rec, sizeof(sportsman), 1, file) == 1) {
        rec ++;
        amount_sportsman++;
    }

    fclose(file);

    file = fopen(fname, "wb");

    if (file == NULL) {
        printf("Error: Don`t read file\n");
        exit(1);
    }

    sort_sportsman(team, amount_sportsman);

    int amount_in_team = amount_sportsman >= n ? n : amount_sportsman;

    for (int i = 0; i < amount_in_team; i++) {
        fwrite(team + i, sizeof(sportsman), 1, file);
    }

    free(team);
    fclose(file);
}
