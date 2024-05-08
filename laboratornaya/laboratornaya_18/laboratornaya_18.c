#include "laboratornaya_18.h"

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

void reverse_words_order(char* string) {
    char* r_begin_src = string + string_strlen(string) - 1;
    char* r_end_src = string - 1;
    char* begin_dst = string_buffer;

    WordDescriptor word;

    while (get_word_reverse(r_end_src, r_begin_src, &word)) {
        begin_dst = string_copy(word.begin, word.end, begin_dst);
        *begin_dst++ = ' ';
        r_begin_src = word.begin - 1;
    }

    *string_copy(string_buffer, begin_dst - (begin_dst != string_buffer), string) = '\0';
}

