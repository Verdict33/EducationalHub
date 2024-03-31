#include "laboratornaya/laboratornaya_16/laboratornaya_16.h"

int test_for_exercise_(){
    matrix *m = matrices_get_mem_array(2, 3, 3);
    matrices_input(m, 2);
    exercise_15(m, 2);
    matrices_free_mem(m, 2);
}

int main(){
    test_for_exercise_();
}