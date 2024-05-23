#include "tests for laboratornaya_19.h"

//Задание 1
void generate_file_test_1(const char *fename, int num_matrices, int max_order, int max_value) {

    FILE *file = fopen(fename, "w");

    if (file == NULL) {
        printf("Error: Don`t open file.\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < num_matrices; ++i) {

        int matrixOrder = rand() % max_order + 1;

        fprintf(file, "%d\n", matrixOrder);

        for (int j = 0; j < matrixOrder; ++j) {
            for (int k = 0; k < matrixOrder; ++k) {

                fprintf(file, "%d ", rand() % (2 * max_value + 1) - max_value);
            }

            fprintf(file, "\n");
        }
    }

    fclose(file);
}

bool compare_files(const char *fname1, const char *fname2) {
    FILE *file1 = fopen(fname1, "r");
    FILE *file2 = fopen(fname2, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error: Don`t open files for comparison.\n");
        return false;
    }

    char char1, char2;

    while ((char1 = fgetc(file1)) != EOF && (char2 = fgetc(file2)) != EOF) {
        if (char1 != char2) {

            fclose(file1);
            fclose(file2);

            return false;
        }
    }

    fclose(file1);
    fclose(file2);

    return true;
}

void create_expect_file(const char *output_fname, const char *expect_fname) {

    FILE *output = fopen(output_fname, "r");
    FILE *expected = fopen(expect_fname, "w");

    if (output == NULL || expected == NULL) {
        printf("Error: Don`t open files for creat expect or output.\n");
        return;
    }

    int char_;

    while ((char_ = fgetc(output)) != EOF) {
        fputc(char_, expected);
    }

    fclose(output);
    fclose(expected);

}

int test_for_task_1() {
    generate_file_test_1("data_test.txt", 4, 4, 10);

    convert_matrix_rows_to_columns("data_test.txt", "output.txt");

    create_expect_file("output.txt", "expect_output.txt");

    if (compare_files("expect_output.txt", "output.txt")) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
    return 0;
}

//Задание 2
bool check_format_convert(const char *fname) {
    FILE *file = fopen(fname, "r");

    if (!file) {
        perror("Don`t open file for checking");
        return false;
    }

    double number;
    bool is_convert = true;

    while (fscanf(file, "%lf", &number) == 1) {

        char buffer[20];

        sprintf(buffer, "%.2e", number);

        if (strcmp(buffer, "0.00e+00") != 0 && strcmp(buffer, "0.00e+000") != 0) {
            is_convert = false;
            break;
        }
    }

    fclose(file);
    return is_convert;
}

void generate_file_test_2(const char *fname, int count) {
    FILE *file = fopen(fname, "w");

    if (!file) {
        perror("Don`t open file for writing");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        double number = (rand() / (double)RAND_MAX) * 2000.0 - 1000.0;
        fprintf(file, "%.6f\n", number);
    }

    fclose(file);
}

int test_for_task_2() {
    const char *input_fname = "data_test.txt";
    const char *output_fname = "data_convert.txt";

    generate_file_test_2(input_fname, 100);

    FILE *input = fopen(input_fname, "r");

    if (!input) {
        perror("Don`t open input file for reading");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_fname, "w");

    if (!output) {
        perror("Don`t open output file for writing");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    convert_to_floating_point(input, output);

    if (check_format_convert(output_fname)) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }

    fclose(input);
    fclose(output);

    return 0;
}

// Задание 4
void generate_file_test_4(const char *fname, int count) {
    const char *word_example[] = {
            "speech", "mode", "replacement", "pollution", "pollution", "advice", "assistant",
            "complaint", "player", "description", "singer", "gene", "decision", "passenger",
            "army", "definition", "speech", "mode", "replacement", "decision", "passenger",
            "description", "singer", "gene", "definition", "speech", "mode","pollution"
    };

    int count_word_example = sizeof(word_example) / sizeof(word_example[0]);

    FILE *file = fopen(fname, "w");

    if (!file) {
        perror("Don`t open file for writing");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int i = 0; i < count; i++) {

        int numWords = rand() % 10 + 1;

        for (int j = 0; j < numWords; j++) {
            fprintf(file, "%s ", word_example[rand() % count_word_example]);
        }

        fprintf(file, "\n");
    }

    fclose(file);
}

int test_for_task_4() {
    const char *input_fname = "input_data.txt";
    const char *output_fname = "output_data.txt";

    generate_file_test_4(input_fname, 10);

    FILE *input = fopen(input_fname, "r");

    if (!input) {
        perror("Don`t open file for reading");
        return 1;
    }

    FILE *output = fopen(output_fname, "w");

    if (!output) {
        perror("Failed to open file for writing");
        fclose(input);
        return 1;
    }

    const char content[] = "an";

    filter_word_by_sample(input, output, content);

    fclose(input);
    fclose(output);

    printf("Filtration is complete\n");

    return 0;
}

// Задание 5

void generate_file_test_5(const char* fname) {
    FILE* file = fopen(fname, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "Test sentence with longeeeeeeest words\n");
    fprintf(file, "Short word\n");
    fprintf(file, "One\n");

    fclose(file);
}

int test_for_task_5() {
    generate_file_test_5("test.txt");

    FILE* input = fopen("test.txt", "r");

    if (input == NULL) {
        printf("Don`t open input file.\n");
        return 1;
    }

    FILE* output = fopen("output.txt", "w");

    if (output == NULL) {
        printf("Don`t open output file.\n");
        fclose(input);
        return 1;
    }

    output_longest_word(input, output);

    fclose(input);
    fclose(output);

    printf("Test passed\n");
    return 0;
}

// Задание 7

void test_reorganization_numbers_only_negative_numbers() {
    const char fname[] = "test.txt";

    int x1 = -1;
    int x2 = -2;
    int x3 = -3;

    FILE* file = fopen(fname, "wb");

    fwrite(&x1, sizeof(int), 1, file);
    fwrite(&x2, sizeof(int), 1, file);
    fwrite(&x3, sizeof(int), 1, file);

    fclose(file);

    reorganization_numbers(fname);

    file = fopen(fname, "rb");

    int res_x1, res_x2, res_x3;
    fread(&res_x1, sizeof(int), 1, file);
    fread(&res_x2, sizeof(int), 1, file);
    fread(&res_x3, sizeof(int), 1, file);

    fclose(file);

    assert(x1 == res_x1);
    assert(x2 == res_x2);
    assert(x3 == res_x3);
}


void test_reorganization_numbers_only_positive_numbers() {
    const char fname[] = "test.txt";

    int x1 = 1;
    int x2 = 2;
    int x3 = 3;

    FILE* file = fopen(fname, "wb");

    fwrite(&x1, sizeof(int), 1, file);
    fwrite(&x2, sizeof(int), 1, file);
    fwrite(&x3, sizeof(int), 1, file);

    fclose(file);

    reorganization_numbers(fname);

    file = fopen(fname, "rb");

    int res_x1, res_x2, res_x3;
    fread(&res_x1, sizeof(int), 1, file);
    fread(&res_x2, sizeof(int), 1, file);
    fread(&res_x3, sizeof(int), 1, file);

    fclose(file);

    assert(x1 == res_x1);
    assert(x2 == res_x2);
    assert(x3 == res_x3);
}


void test_reorganization_numbers_mixed_numbers() {
    const char fname[] = "test.txt";

    int x1 = -1;
    int x2 = 1;
    int x3 = -3;
    int x4 = 3;

    FILE* file = fopen(fname, "wb");

    fwrite(&x1, sizeof(int), 1, file);
    fwrite(&x2, sizeof(int), 1, file);
    fwrite(&x3, sizeof(int), 1, file);
    fwrite(&x4, sizeof(int), 1, file);

    fclose(file);

    reorganization_numbers(fname);

    file = fopen(fname, "rb");

    int res_x1, res_x2, res_x3, res_x4;
    fread(&res_x1, sizeof(int), 1, file);
    fread(&res_x2, sizeof(int), 1, file);
    fread(&res_x3, sizeof(int), 1, file);
    fread(&res_x4, sizeof(int), 1, file);

    fclose(file);

    assert(res_x1 == x2);
    assert(res_x2 == x4);
    assert(res_x3 == x1);
    assert(res_x4 == x3);
}


void test_for_task_7() {
    test_reorganization_numbers_only_negative_numbers();
    test_reorganization_numbers_only_positive_numbers();
    test_reorganization_numbers_mixed_numbers();
}

// Задание 9


void test_get_best_team_n_one() {
    const char fname[] = "test.txt";

    FILE* file = fopen(fname, "wb");

    sportsman s1 = {.best_result = 8.1, .name="first"};
    sportsman s2 = {.best_result = 7.2,  .name="second"};

    fwrite(&s1, sizeof(sportsman), 1, file);
    fwrite(&s2, sizeof(sportsman), 1, file);

    fclose(file);

    get_best_team(fname, 1);

    file = fopen(fname, "rb");

    sportsman res_s1;
    fread(&res_s1, sizeof(sportsman), 1, file);

    fclose(file);

    assert(string_strcmp(s1.name, res_s1.name) == 0 && fabs(s1.best_result - res_s1.best_result) <= 0.001);
}

void test_get_best_team_n_more() {
    const char fname[] = "test.txt";

    FILE* file = fopen(fname, "wb");

    sportsman s1 = {.best_result = 8.1, .name="first"};
    sportsman s2 = {.best_result = 7.2,  .name="second"};

    fwrite(&s1, sizeof(sportsman), 1, file);
    fwrite(&s2, sizeof(sportsman), 1, file);

    fclose(file);

    get_best_team(fname, 2);

    file = fopen(fname, "rb");

    sportsman res_s1, res_s2;
    fread(&res_s1, sizeof(sportsman), 1, file);
    fread(&res_s2, sizeof(sportsman), 1, file);

    fclose(file);

    assert(string_strcmp(s1.name, res_s1.name) == 0 && fabs(s1.best_result - res_s1.best_result) <= 0.001);
    assert(string_strcmp(s2.name, res_s2.name) == 0 && fabs(s2.best_result - res_s2.best_result) <= 0.001);
}


void test_for_task_9() {
    test_get_best_team_n_one();
    test_get_best_team_n_more();
}