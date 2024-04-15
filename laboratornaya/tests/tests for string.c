#include "../../laboratornaya/tests/tests for string.h"

void test_string_strlen() {
    char *s1 = "Hi";
    char s2[10] = "\tHello\t";
    printf("%u\n", string_strlen(s1)); // 2
    printf("%u\n", string_strlen(s2)); // 7
}

int test_string_find_(char *s, int ch) {
    char *result = string_find(s, s + string_strlen(s), ch);
    return (result != s + string_strlen(s)) ? 1 : 0;
}

void test_string_find() {
    char s[] = "Hello, World!";
    printf("%d\n", test_string_find_(s, 'W')); // 1
    printf("%d\n", test_string_find_(s, 'c')); // 0
    printf("%d\n", test_string_find_(s, 'a')); // 0
}

int test_string_find_non_space_(char *s) {
    char *result = string_find_non_space(s);
    return (*result != '\0') ? 1 : 0;
}

void test_string_find_non_space() {
    char s[] = "  Hello, World!";
    printf("%d\n", test_string_find_non_space_(s)); // 1
    printf("%d\n", test_string_find_non_space_("  ")); // 0
    printf("%d\n", test_string_find_non_space_("")); // 0
}

int test_string_find_space_(char *s) {
    char *result = string_find_space(s);
    return (*result == ' ') ? 1 : 0;
}

void test_string_find_space() {
    char s[] = "Hello,World!";
    printf("%d\n", test_string_find_space_(s)); // 0
    printf("%d\n", test_string_find_space_("  Hello, World!")); // 1
    printf("%d\n", test_string_find_space_("")); // 0
}

int test_string_find_non_space_reverse_(char *s) {
    char *result = string_find_non_space_reverse(s + string_strlen(s) - 1, s - 1);
    return (*result != '\0') ? 1 : 0;
}

void test_string_find_non_space_reverse() {
    char s[] = "Hello, World!";
    printf("%d\n", test_string_find_non_space_reverse_(s)); // 1
    printf("%d\n", test_string_find_non_space_reverse_("  Hello, World!")); // 1
    printf("%d\n", test_string_find_non_space_reverse_("")); // 0
}

void test_string_find_space_reverse() {
    char s1[] = "Hello,World!";
    char *result = string_find_space_reverse(s1 + string_strlen(s1) - 1, s1 - 1);
    if (result != s1 - 1) {
        printf("%d", 0);
    } else {
        printf("%d", 1);
    }
}

void test_string_strcmp() {
    char s1[] = "C";
    char s2[] = "B";
    int result1 = string_strcmp(s1, s2);

    char s3[] = "C";
    char s4[] = "C";
    int result2 = string_strcmp(s3, s4);

    char s5[] = "B";
    char s6[] = "C";
    int result3 = string_strcmp(s5, s6);

    printf("%d\n", result1); //-1
    printf("%d\n", result2); // 0
    printf("%d\n", result3); // 1
}

void test_string_copy() {
    const char *source = "Hello, World!";
    const char *sourceBegin = source;
    const char *sourceEnd = source + string_strlen(source);

    char destination[20];
    char *destinationBegin = destination;
    char *result = string_copy(sourceBegin, sourceEnd, destinationBegin);

    if (string_strcmp(destination, source) == 0 && result == destinationBegin + string_strlen(source)) {
        printf("%d", 1);
    } else {
        printf("%d", 0);
    }
}

int is_lower_case(int ch) {
    return (ch >= 'a' && ch <= 'z');
}

void test_string_copy_if() {
    char source[] = "ABCd";
    char destination[20] = {0};
    char *result = string_copy_if(source, source + string_strlen(source), destination, is_lower_case);
    *result = '\0';
    printf("%s\n", destination); //d
}

void test_string_copy_if_reverse() {
    char source[] = "Hello, World!";
    char destination[20] = {0};
    char *result = string_copy_if_reverse(source + string_strlen(source) - 1, source - 1, destination + string_strlen(source) - 1, isalpha);
    printf("%s\n", result + 1); //HelloWorld
}