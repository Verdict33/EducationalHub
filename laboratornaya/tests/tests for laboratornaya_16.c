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

int test_for_exercise_6(){
    matrix m1 = matrix_get_mem(3, 3);
    matrix m2 = matrix_get_mem(3, 3);
    matrix_input(&m1);
    matrix_input(&m2);
    printf("%d", exercise_6(m1, m2));
    matrix_free_mem(&m1);
    matrix_free_mem(&m2);
}

int test_for_exercise_8(){
    matrix m1 = matrix_get_mem(3, 3);
    matrix_input(&m1);
    printf("%d", exercise_8(m1));
    matrix_free_mem(&m1);
}

int test_for_exercise_10(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    printf("%d", exercise_10(m));
    matrix_free_mem(&m);
}

int test_for_exercise_11(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    printf("%d", exercise_11(m));
    matrix_free_mem(&m);
}

int test_for_exercise_12(){
    matrix m = matrix_get_mem(3, 3);
    matrix_input(&m);
    exercise_12(m);
    matrix_output(m);
    matrix_free_mem(&m);
}

int test_for_exercise_13(){
    matrix *m = matrices_get_mem_array(2, 3, 3);
    matrices_input(m, 2);
    printf("%d", exercise_13(m, 2));
    matrices_free_mem(m, 2);
}

int test_for_exercise_14(){
    matrix *m = matrices_get_mem_array(2, 3, 3);
    matrices_input(m, 2);
    exercise_14(m, 2);
    matrices_free_mem(m, 2);
}

int test_for_exercise_15(){
    matrix *m = matrices_get_mem_array(2, 3, 3);
    matrices_input(m, 2);
    exercise_15(m, 2);
    matrices_free_mem(m, 2);
}