#include <stdio.h>
#include "libs/algorithms/array/array.h"

size_t ordered_array_set_union(int *set, size_t n_set, int *subset, size_t n_subset, int *set_result){
    size_t n_set_result = 0;

    for(int i = 0; i < n_set; i++)
        set_result[n_set_result++] = set[i];

    for(int i = 0; i < n_subset; i++){
        int is_union = 1;

        for(int j = 0; j < n_set_result; j++){
            if(subset[i] == set_result[j]){
                is_union = 0;
                break;
            }
        }
        if(is_union)
            set_result[n_set_result++] = subset[i];
    }

    return n_set_result;
}


int main() {
    int n_a, n_b, n_c;
    scanf("%d %d", &n_a, &n_b);

    int a[n_a];
    inputArray_(a, n_a);

    int b[n_b];
    inputArray_(b, n_b);

    int c[n_c];
    n_c = ordered_array_set_union(a, n_a, b, n_b, c);

    outputArray_(c, n_c);
}