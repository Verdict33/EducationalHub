#include "vectorVoid.h"

vectorVoid vector_void_create(size_t n, size_t baseTypeSize){
    if (malloc(sizeof(baseTypeSize) * n) == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid){malloc(sizeof(baseTypeSize) * n), 0, n, baseTypeSize};
}


void vector_void_reserve(vectorVoid *v, size_t newCapacity){
    if (newCapacity == 0) {
        free(v->data);
    } else {

        void *newData = realloc(v->data, newCapacity * v->baseTypeSize);

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


void vector_void_shrinkToFit(vectorVoid *v){
    vector_void_reserve(v, v->size);
}


void vector_void_clear(vectorVoid *v){
    v->size = 0;
}


void vector_void_delete(vectorVoid *v){
    free(v->data);
}


bool vector_void_isEmpty(vectorVoid *v){
    return (v->size == 0);
}


bool vector_void_isFull(vectorVoid *v){
    return (v->size == v->capacity);
}


void vector_void_get_value(vectorVoid *v, size_t index, void *destination){
    if (v == NULL || destination == NULL) {
        fprintf(stderr, "Error: NULL pointer argument detected\n");
        exit(1);
    }

    if (index >= v->size) {
        fprintf(stderr, "Error: Index %zu is out of bounds (vector size: %zu)\n", index, v->size);
        exit(1);
    }
    // Получить адрес начала данных для index-ого элемента вектора
    char *source = (char *) v->data + index * v->baseTypeSize;
    // Копирование данных из вектора в destination
    memcpy(destination, source, v->baseTypeSize);
}


void vector_void_set_value(vectorVoid *v, size_t index, void *source){
    if (v == NULL || source == NULL) {
        fprintf(stderr, "Error: NULL pointer argument detected\n");
        exit(1);
    }

    if (index >= v->size) {
        fprintf(stderr, "Error: Index %zu is out of bounds (vector size: %zu)\n", index, v->size);
        exit(1);
    }
    // Вычислить адрес для index-ого элемента вектора и копировать данные
    char *destination = (char *)(v->data + index * v->baseTypeSize);
    memcpy(destination, source, v->baseTypeSize);
}


void vector_void_popBack(vectorVoid *v){
    if(vector_void_isEmpty(v)){
        fprintf(stderr, "vector is empty");
        exit(1);
    } else{
        v->size--;
        vector_void_shrinkToFit(v);
    }
}


void vector_void_pushBack(vectorVoid *v, void *source){
    if (vector_void_isFull(v)) {
        vector_void_reserve(v, v->capacity == 0 ? 1 : v->capacity * 2);
    }

    char *destination = (char *)(v->data + v->size++ * v->baseTypeSize);

    memcpy(destination, source, v->baseTypeSize);
}