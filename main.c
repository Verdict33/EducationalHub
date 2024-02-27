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

void test_atVector_notEmptyVector(){
    vector v = createVector(3);
    pushBack(&v, 5);
    pushBack(&v, 7);
    pushBack(&v, 8);
    int *index = atVector(&v, 1);
    assert(*index == 7);
}

void test_atVector_requestToLastElement(){
    vector v = createVector(3);
    pushBack(&v, 5);
    pushBack(&v, 7);
    pushBack(&v, 8);
    int *index = atVector(&v, 2);
    assert(*index == 8);
}

void test_back_oneElementInVector(){
    vector v = createVector(1);
    pushBack(&v, 5);
    int *index = back(&v);
    assert(*index == 5);
}

void test_front_oneElementInVector(){
    vector v = createVector(1);
    pushBack(&v, 5);
    int *index = front(&v);
    assert(*index == 5);
}

void test(){
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}


int main() {

    test();

    return 0;
}
