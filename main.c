#include "laboratornaya/laboratornaya_16/laboratornaya_16.h"

int test_for_exercise_(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    printf("%d", exercise_10(m));
    matrix_free_mem(&m);
}

int main(){
    test_for_exercise_();
}