#include "../../data_structures/string/string.h"

size_t string_strlen(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* string_find(char *begin, char *end, int ch){
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char* string_find_non_space(char *begin){
    while (begin != '/0' && isspace(*begin))
        begin++;

    return begin;
}

char* string_find_space(char *begin){
    while (begin != '/0' && !isspace(*begin))
        begin++;

    return begin;
}

char* string_find_non_space_reverse(char *rbegin, const char *rend){
    while(rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char* string_find_space_reverse(char *rbegin, const char *rend){
    while(rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int string_strcmp(const char *lhs, const char *rhs){

}

char* string_copy(const char *beginSource, const char *endSource, char *beginDestination){

}

char* string_copy_if(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)){

}

char* string_copy_if_reverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)){

}