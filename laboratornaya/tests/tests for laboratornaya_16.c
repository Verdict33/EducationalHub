#include "../../laboratornaya/laboratornaya_16/laboratornaya_16.h"
#include "../../laboratornaya/tests/tests for laboratornaya_16.h"
int test_for_exercise_1(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    exercise_1(m);
    matrix_output(m);
    matrix_free_mem(&m);
}


int test_for_exercise_2(){
    matrix m = matrix_get_mem(4, 4);
    matrix_input(&m);
    exercise_2(m);
    matrix_output(m);
    matrix_free_mem(&m);
}


int test_for_exercise_3(){
    matrix m = matrix_get_mem(3, 6);
    matrix_input(&m);
    exercise_3(m);
    matrix_output(m);
    matrix_free_mem(&m);
}


int test_for_exercise_4(){
    matrix m = matrix_get_mem(4, 4);
    matrix_input(&m);
    exercise_4(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int test_for_exercise_5(){
    matrix m = matrix_get_mem(4, 4);
    matrix_input(&m);
    exercise_5(m);
    matrix_output(m);
    matrix_free_mem(&m);
}
