//#include "libs/data_structures/vector/vector.h"
//#include <assert.h>
//
//void test_pushBack_emptyVector(){
//    vector a = createVector(0);
//    pushBack(&a, 10);
//    deleteVector(&a);
//}
//
//void test_pushBack_fullVector(){
//    vector v = createVector(2);
//    pushBack(&v, 5);
//    pushBack(&v, 1);
//    assert(v.size == 2);
//    pushBack(&v, 7);
//    assert(v.size == 3);
//    assert(v.capacity == 4);
//}
//
//void test_popBack_notEmptyVector() {
//    vector v = createVector(0);
//    pushBack(&v, 10);
//    assert(v.size == 1);
//    popBack(&v);
//    assert(v.size == 0);
//    assert(v.capacity == 1);
//}
//
//void test_atVector_notEmptyVector(){
//    vector v = createVector(3);
//    pushBack(&v, 5);
//    pushBack(&v, 7);
//    pushBack(&v, 8);
//    int *index = atVector(&v, 1);
//    assert(*index == 7);
//}
//
//void test_atVector_requestToLastElement(){
//    vector v = createVector(3);
//    pushBack(&v, 5);
//    pushBack(&v, 7);
//    pushBack(&v, 8);
//    int *index = atVector(&v, 2);
//    assert(*index == 8);
//}
//
//void test_back_oneElementInVector(){
//    vector v = createVector(1);
//    pushBack(&v, 5);
//    int *index = back(&v);
//    assert(*index == 5);
//}
//
//void test_front_oneElementInVector(){
//    vector v = createVector(1);
//    pushBack(&v, 5);
//    int *index = front(&v);
//    assert(*index == 5);
//}
//
//void test(){
//    test_pushBack_emptyVector();
//    test_pushBack_fullVector();
//    test_popBack_notEmptyVector();
//    test_atVector_notEmptyVector();
//    test_atVector_requestToLastElement();
//    test_back_oneElementInVector();
//    test_front_oneElementInVector();
//}
//
//
//
//int main() {
//
//    test();
//
//    return 0;
//}

#include "libs/data_structures/matrix/matrix.h"

int sum(int *a, int n){
    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    return s;
}

void test(){
    int a[9] = {2,2,3,4, 6,8,9,9,9};

    int b[6] = {2,2,3,4, 6,8};

    matrix m = createMatrixFromArray(a, 3, 3);

    matrix c = createMatrixFromArray(b, 3, 3);

    insertionSortRowsMatrixByRowCriteria(m, sum);

    selectionSortColsMatrixByColCriteria(m, sum);

    isSquareMatrix(&m);

    areTwoMatricesEqual(&m, &c);

    isEMatrix(&m);

    isSymmetricMatrix(&m);

    transposeSquareMatrix(&m);

    transposeMatrix(&m);

    getMinValuePos(m);

    getMaxValuePos(m);

    freeMemMatrix(&m);

    freeMemMatrix(&c);
}

int main(){

    test();

}