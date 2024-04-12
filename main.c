#include <stdio.h>

size_t unordered_array_set_union(int *set, size_t n_set, int *subset, size_t
n_subset, int *set_result){
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

size_t unordered_array_set_intersection(int *set, size_t n_set, int *subset,
                                        size_t n_subset, int *set_result){
    size_t n_set_result = 0;
    for(int i = 0; i < n_set; i++){
        for(int j = 0; j < n_subset; j++){
            if(set[i] == subset[j]){
                int is_unical = 1;
                for(int k = 0; k < n_set_result; k++){
                    if(set[i] == set_result[k]){
                        is_unical = 0;
                        break;

                    }
                }
                if(is_unical)
                    set_result[n_set_result++] = set[i];
            }
        }
    }
    return n_set_result;
}

size_t unordered_array_set_difference(int *set1, size_t n_set1, int *set2,
                                      size_t n_set2, int *set_result) {
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

int unordered_array_set_symmetric_difference(int *set1, size_t n_set1, int
*set2, size_t n_set2, int *result) {
    int temp_set_1[n_set1 + n_set2];
    int temp_set_2[n_set1 + n_set2];
    int first_difference = unordered_array_set_difference(set1, n_set1, set2,
                                                          n_set2, temp_set_1);
    int second_difference = unordered_array_set_difference(set2, n_set2,
                                                           set1, n_set1, temp_set_2);
    int necessary_elements =
            unordered_array_set_union(temp_set_1,first_difference,temp_set_2,second_difference,result);
    return necessary_elements;
}

size_t unordered_array_set_complement(int *set, size_t n_set, int *comp,
                                      size_t n_comp, int *set_result){
    size_t n_set_result = unordered_array_set_difference(comp, n_comp, set,
                                                         n_set, set_result);
    return n_set_result;
}

int main() {

    int n_comp = 1;
    int Comp[1] = {1};

    int n_a = 1;
    int A[1] = {1};

    int n_b = 1;
    int B[1] = {1};

    int n_c = 1;
    int C[1] = {1};

    int n_res1;
    int result1[1];

    int n_res2;
    int result2[1];

    int n_res3;
    int result3[1];

    int n_res4;
    int result4[1];

    int n_res5;
    int result5[1];

    int n_res6;
    int result6[1];

    int n_res7;
    int result7[1];

    int n_res8;
    int result8[1];

    n_res1 = unordered_array_set_union(A, n_a, B, n_b, result1);

    n_res2 = unordered_array_set_complement(A, n_a, Comp, n_comp, result2);;

    n_res3 = unordered_array_set_union(result2, n_res2, B, n_b, result3);

    n_res4 = unordered_array_set_complement(B, n_b, Comp, n_comp, result4);

    n_res5 = unordered_array_set_complement(C, n_c, Comp, n_comp, result5);

    n_res6 = unordered_array_set_intersection(result3, n_res3, result4, n_res4, result6);

    n_res7 = unordered_array_set_union(result6, n_res6, result5, n_res5, result7);

    n_res8 = unordered_array_set_intersection(result1, n_res1, result7, n_res7, result8);

    printf("%d", n_res8);
    return 0;
}

