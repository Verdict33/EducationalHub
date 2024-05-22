#include "vector.h"

vector vector_create(size_t capacity){
    if (malloc(sizeof(int) * capacity) == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector){malloc(sizeof(int) * capacity), 0, capacity};
}


void vector_reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
    } else {

        int *newData = realloc(v->data, newCapacity * sizeof(int));

        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        } else {
            if (newCapacity <= v->size)
                v->size = newCapacity;

            v->data = newData;
            v->capacity = newCapacity;
        }
    }
}


void vector_clear(vector *v){
    v->size = 0;
}


void vector_shrinkToFit(vector *v){
    vector_reserve(v, v->size);
}


void vector_delete(vector *v){
    free(v->data);
}


bool vector_isEmpty(vector *v){
    return (v->size == 0);
}


bool vector_isFull(vector *v){
    return (v->size == v->capacity);
}


int vector_get_value(vector *v, size_t i){
    return i > v->size ? -1 : v->data[i];
}


void vector_pushBack(vector *v, int x){
    if(v->capacity == 0)
        vector_reserve(v, 1);
    else if (v->size == v->capacity)
        vector_reserve(v, v->capacity * 2);

    v->data[v->size++] = x;
}


void vector_popBack(vector *v){
    if(vector_isEmpty(v)){
        fprintf(stderr, "vector is empty");
        exit(1);
    } else{
        v->size--;
        vector_shrinkToFit(v);
    }
}


int *vector_at(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
    return &v->data[index];
}


int* vector_back(vector *v){
    return &v->data[v->size - 1];
}


int* vector_front(vector *v){
    return &v->data[0];
}

int vector_output(vector v){
    for (int i = 0; i < v.size; ++i) {
        printf("%d ", v.data[i]);
    }
}