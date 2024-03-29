#include "laboratornaya/laboratornaya_16/laboratornaya_16.h"

int test_for_exercise_(){
    matrix m = matrix_get_mem(4, 4);
    matrix_input(&m);
    exercise_5(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int main(){
    test_for_exercise_();
}
//123