#include "../../libs/data_structures/string/string.h"
#include <stdlib.h>
#include "stdbool.h"

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

typedef struct WordDescriptor {
    char* begin;
    char* end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

static char string_buffer[MAX_STRING_SIZE + 1];

static BagOfWords bag1;
static BagOfWords bag2;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

//Сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char* source);

//Преобразует строку, обратив каждое слово этой строки.
int get_word_reverse(char* rbegin, char* rend, WordDescriptor* word);

// Выводит слова данной строки в обратном порядке по одному в строке экрана
void outputWordsInReverseOrder(char* string);

// Определяет количество слов полиндромов в данной строке
int numbers_palindromes(char* string);

//Выводит слово данной строки, предшествующее первому из слов, содержащих букву symbol
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithSymbol(char* string, WordDescriptor* word, char symbol);

//
bool findLastEqualWordInBothStr(char* string, char* word, WordDescriptor* lastWord);

//
