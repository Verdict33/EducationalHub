#include <stdio.h>
#include "libs/algorithms/array/array.h"

size_t unordered_array_set_union(int *set, size_t n_set, int *subset, size_t n_subset, int *set_result){
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

size_t unordered_array_set_difference(int *set1, size_t n_set1, int *set2, size_t n_set2, int *set_result) {
    int n_set_result = 0;

    for (int i = 0; i < n_set1; i++) {
        int found = 0;

        for (int j = 0; j < n_set2; j++) {
            if (set1[i] == set2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            set_result[n_set_result] = set1[i];
            n_set_result++;
        }
    }
    return n_set_result;
}

int unordered_array_set_symmetric_difference(int *set1, size_t n_set1, int *set2, size_t n_set2, int *result) {
    int temp_set_1[n_set1 + n_set2];
    int temp_set_2[n_set1 + n_set2];

    int first_difference = unordered_array_set_difference(set1, n_set1, set2, n_set2, temp_set_1);
    int second_difference = unordered_array_set_difference(set2, n_set2, set1, n_set1, temp_set_2);

    int necessary_elements = unordered_array_set_union(temp_set_1,first_difference,temp_set_2,second_difference,result);

    return necessary_elements;
}

int main() {
    int n_a, n_b, n_c;
    scanf("%d %d", &n_a, &n_b);

    int a[n_a];
    inputArray_(a, n_a);

    int b[n_b];
    inputArray_(b, n_b);

    int c[n_c];
    n_c = unordered_array_set_symmetric_difference(a, n_a, b, n_b, c);

    outputArray_(c, n_c);
}


