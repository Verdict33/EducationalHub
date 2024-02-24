#include "vector.h"

vector createVector(size_t capacity){
    if (malloc(sizeof(int) * capacity) == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector){malloc(sizeof(int) * capacity), 0, capacity};
}


void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);

    }else{
        int *newData = realloc(v->data, newCapacity * sizeof(int));

        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        } else {
            if (newCapacity <= v->size)
                v->size = newCapacity;
            free(v->data);
            v->data = newData;
            v->capacity = newCapacity;
        }
    }
}



void clear(vector *v){
    v->size = 0;
}


void shrinkToFit(vector *v){
    reserve(v, v->size);
}


void deleteVector(vector *v){
    free(v->data);
}