#include "laboratornaya/laboratornaya_16/laboratornaya_16.h"

int test (){
    matrix m = matrix_get_mem(3, 6);
    matrix_input(&m);
    exercise_3(m);
    matrix_output(m);
}

int main(){
    test();
}