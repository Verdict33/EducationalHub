#include "labornatornaya_18.h"

void removeExtraSpaces(char* source) {
    char* writePointer = source;

    while (*source != '\0') {
        if (*source != *(source + 1)) {
            *writePointer = *source;
            writePointer++;
        }
        source++;
    }
    *writePointer = '\0';
}

int getWord(char *beginSearch, WordDescriptor* word) {
    word->begin = string_find_non_space(beginSearch);

    if (*word->begin == '\0') {
        return 0;
    }

    word->end = string_find_space(word->begin);

    return 1;
}

int get_word_reverse(char* searchEnd, char* searchStart, WordDescriptor* word) {
    word->end = string_find_non_space_reverse(searchEnd, searchStart) + 1;

    if (word->end == searchEnd + 1) {
        word->begin = searchStart + 1;
        return 0;
    }

    word->begin = string_find_space_reverse(searchEnd, word->end - 1) + 1;

    return 1;
}

static void getBagOfWords(BagOfWords* bag, char* searchStart) {
    size_t wordIndex = 0;

    while (getWord(searchStart, bag->words + wordIndex)) {
        searchStart = bag->words[wordIndex].end;
        wordIndex++;
    }

    bag->size = wordIndex;
}

void print_word(WordDescriptor word) {
    if (*word.begin == '\0') {
        return;
    }

    while (word.begin != word.end) {
        putc(*word.begin, stdout);
        word.begin++;
    }
}

void outputWordsInReverseOrder(char* string) {
    getBagOfWords(string, &bag1);

    for (size_t i = bag1.size - 1; i != -1; i--) {
        print_word(bag1.words[i]);
        putchar('\n');
    }
}

static bool isPalindrome(WordDescriptor word) {
    word.end--;

    while (word.begin < word.end) {
        if (*word.begin != *word.end) {
            return false;
        }

        word.begin++;
        word.end--;
    }

    return true;
}

int numbers_palindromes(char* string) {
    int count = 0;
    char* searchPoint = string;
    WordDescriptor word;

    while (getWord(searchPoint, &word)) {
        if (isPalindrome(word)) {
            count++;
        }

        searchPoint = word.end;
    }

    return count;
}

static bool isSymbolInWord(WordDescriptor word, const char symbol) {
    return string_find(word.begin, word.end, symbol) != word.end;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithSymbol(char* string, WordDescriptor* word, char symbol) {
    WordDescriptor previousWord;

    if (getWord(string, &previousWord)) {
        if (!isSymbolInWord(previousWord, symbol)) {
            string = previousWord.end;
            WordDescriptor next_word;

            while (getWord(string, &next_word)) {
                if (isSymbolInWord(next_word, symbol)) {
                    *word = previousWord;
                    return WORD_FOUND;
                }

                previousWord = next_word;
                string = previousWord.end;
            }

            return NOT_FOUND_A_WORD_WITH_A;
        }

        return FIRST_WORD_WITH_A;
    }

    return EMPTY_STRING;
}

int words_compare_(WordDescriptor left, WordDescriptor right) {
    while (left.begin != left.end && right.begin != right.end && *left.begin == *right.begin) {
        left.begin++;
        right.begin++;
    }

    if (left.begin == left.end && right.begin == right.end) {
        return 0;
    }

    if (left.begin == left.end && right.begin != right.end) {
        return -(*right.begin);
    }

    if (left.begin != left.end && right.begin == right.end) {
        return *left.begin;
    }

    return *left.begin - *right.begin;
}

static bool isWordFound(char* string, WordDescriptor word) {
    WordDescriptor currentWord;

    while (getWord(string, &currentWord)) {
        if (words_compare_(word, currentWord) == 0) {
            return true;
        }

        string = currentWord.end;
    }

    return false;
}

bool findLastEqualWordInBothStr(char* string, char* word, WordDescriptor* lastWord) {
    char* searchEnd = string - 1;
    char* searchStart = string + string_strlen(string) - 1;
    WordDescriptor currentWord;

    while (get_word_reverse(searchEnd, searchStart, &currentWord)) {
        if (isWordFound(word, currentWord)) {
            *lastWord = currentWord;

            return true;
        }

        searchStart = currentWord.begin - 1;
    }

    return false;
}

static int word_compare(const void* left, const void* right) {
    return words_compare_(*(WordDescriptor *) left, *(WordDescriptor *) right);
}

bool hasStringEqualWords(char* string) {
    getBagOfWords(string, &bag1);

    qsort(bag1.words, bag1.size, sizeof(*bag1.words), word_compare);

    for (size_t i = 1; i < bag1.size; i++) {
        if (words_compare_(bag1.words[i], bag1.words[i - 1]) == 0) {
            return true;
        }
    }

    return false;
}
