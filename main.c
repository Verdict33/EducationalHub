#include "laboratornaya/laboratornaya_16/laboratornaya_16.h"

int test (){
    matrix m = matrix_get_mem(4, 4);
    matrix_input(&m);
    exercise_4(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int main(){
    test();
}