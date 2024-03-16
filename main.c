/*
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector(){
    vector a = vector_create(0);
    vector_pushBack(&a, 10);
    vector_delete(&a);
}

void test_pushBack_fullVector(){
    vector v = vector_create(2);
    vector_pushBack(&v, 5);
    vector_pushBack(&v, 1);
    assert(v.size == 2);
    vector_pushBack(&v, 7);
    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_popBack_notEmptyVector() {
    vector v = vector_create(0);
    vector_pushBack(&v, 10);
    assert(v.size == 1);
    vector_popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector(){
    vector v = vector_create(3);
    vector_pushBack(&v, 5);
    vector_pushBack(&v, 7);
    vector_pushBack(&v, 8);
    int *index = vector_at(&v, 1);
    assert(*index == 7);
}

void test_atVector_requestToLastElement(){
    vector v = vector_create(3);
    vector_pushBack(&v, 5);
    vector_pushBack(&v, 7);
    vector_pushBack(&v, 8);
    int *index = vector_at(&v, 2);
    assert(*index == 8);
}

void test_back_oneElementInVector(){
    vector v = vector_create(1);
    vector_pushBack(&v, 5);
    int *index = vector_back(&v);
    assert(*index == 5);
}

void test_front_oneElementInVector(){
    vector v = vector_create(1);
    vector_pushBack(&v, 5);
    int *index = vector_front(&v);
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
*/

/*
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

    matrix m = matrix_create_from_array(a, 3, 3);

    matrix c = matrix_create_from_array(b, 3, 3);

    matrix_insertion_sort_rows_by_row_criteria(m, sum);

    matrix_selection_sort_cols_by_col_criteria(m, sum);

    matrix_isSquare(&m);

    matrices_two_areEqual(&m, &c);

    matrix_isE(&m);

    matrix_isSymmetric(&m);

    matrix_transpose_square(&m);

    matrix_transpose(&m);

    matrix_get_min_value_pos(m);

    matrix_get_max_value_pos(m);

    matrix_free_mem(&m);

    matrix_free_mem(&c);
}

int main(){

    test();

}
 */