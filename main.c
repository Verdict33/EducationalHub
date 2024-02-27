#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector(){
    vector a = createVector(0);
    pushBack(&a, 10);
    deleteVector(&a);
}

void test_pushBack_fullVector(){
    vector v = createVector(2);
    pushBack(&v, 5);
    pushBack(&v, 1);
    assert(v.size == 2);
    pushBack(&v, 7);
    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test(){
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}


int main() {

    test();

    return 0;

}
