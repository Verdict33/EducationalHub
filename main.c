#include "laboratornaya/laboratornaya_16/laboratornaya_16.h"

int test_for_exercise_(){
    matrix m1 = matrix_get_mem(3, 3);
    matrix m2 = matrix_get_mem(3, 3);
    matrix_input(&m1);
    matrix_input(&m2);
    printf("%d", exercise_6(m1, m2));
    matrix_free_mem(&m1);
    matrix_free_mem(&m2);
}

int main(){
    test_for_exercise_();
}