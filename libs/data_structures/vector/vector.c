#include "vector.h"

vector createVector(size_t capacity){
    if (malloc(sizeof(int) * capacity) == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector){malloc(sizeof(int) * capacity), 0, capacity};
}

void reserve(vector *v, size_t newCapacity){
    realloc(v->data, newCapacity);
}


void deleteVector(vector *v){
    free(v->data);
}