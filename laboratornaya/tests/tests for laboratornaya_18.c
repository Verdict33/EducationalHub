#include "../../laboratornaya/tests/tests for laboratornaya_18.h"


#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define ASSERT_INT(expected, got) assertInt(expected, got, __FILE__, __FUNCTION__, __LINE__)

static void assertString(char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (string_strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stdout, "%s on line %d - OK\n", funcName, line);
    }
}

static void assertInt(int expected, int got, char const *fileName, char const *funcName, int line) {
    if (got != expected) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%d\"\n", expected);
        fprintf(stderr, "Got: \"%d\"\n\n", got);
    } else {
        fprintf(stdout, "%s on line %d - OK\n", funcName, line);
    }
}

void printTest(char* testableComponent, void (*testingFunction)()) {
    printf("Testing %s:\n\n", testableComponent);

    testingFunction();

    printf("\n///////////////////////////////////////\n\n");
}

char* string_to_heap(char* string) {
    size_t size = sizeof(char) * (string_strlen(string) + 1);
    char* heapString = malloc(size);

    memcpy(heapString, string, size);

    return heapString;
}

static void testRemoveExtraSpaces() {
    char* first_test = string_to_heap("");
    char* second_test = string_to_heap("123  456");
    char* third_test = string_to_heap("123 456  789");

    removeExtraSpaces(first_test);
    removeExtraSpaces(second_test);
    removeExtraSpaces(third_test);

    ASSERT_STRING("", first_test);
    ASSERT_STRING("123 456", second_test);
    ASSERT_STRING("123 456 789", third_test);

    free(first_test);
    free(second_test);
    free(third_test);
}

void test_numbers_palindromes() {
    char* firstTest = string_to_heap("");
    char* secondTest = string_to_heap("abc def");
    char* thirdTest = string_to_heap("abba ceec cde beeb");

    ASSERT_INT(0, numbers_palindromes(firstTest));
    ASSERT_INT(0, numbers_palindromes(secondTest));
    ASSERT_INT(3, numbers_palindromes(thirdTest));

    free(firstTest);
    free(secondTest);
    free(thirdTest);
}

void testReverseWordsOrder() {
    char* test = string_to_heap("I wonder how much a beautiful life costs");

    reverse_words_order(test);

    ASSERT_STRING("costs life beautiful a much how wonder I", test);

    free(test);
}

int test_string_ex_all() {
    printTest("removeExtraSpaces", testRemoveExtraSpaces);

    printTest("numbers_palindromes", test_numbers_palindromes);

    printTest("reverseWordsOrder", testReverseWordsOrder);

}