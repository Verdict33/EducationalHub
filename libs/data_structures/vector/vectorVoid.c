#include "vectorVoid.h"

vectorVoid createVectorVoid(size_t n, size_t baseTypeSize){
    if (malloc(sizeof(baseTypeSize) * n) == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid){malloc(sizeof(baseTypeSize) * n), 0, n, baseTypeSize};
}


void reserveVoid(vectorVoid *v, size_t newCapacity){
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


void shrinkToFitVoid(vectorVoid *v){
    reserveVoid(v, v->size);
}


void clearVoid(vectorVoid *v){
    v->size = 0;
}


void deleteVectorVoid(vectorVoid *v){
    free(v->data);
}