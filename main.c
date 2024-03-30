#include "laboratornaya/laboratornaya_16/laboratornaya_16.h"

int test_for_exercise_(){
    matrix m1 = matrix_get_mem(3, 3);
    matrix_input(&m1);
    printf("%d", exercise_8(m1));
    matrix_free_mem(&m1);
}

int main(){
    test_for_exercise_();
}