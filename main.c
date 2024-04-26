#include <stdio.h>

void array_output(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

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

int unordered_array_set_intersection(int *set1, size_t size_set1, int *set2, size_t size_set2, int
*set_intersection) {
    int amount_elements = 0;
    for(int i= 0; i<size_set1;i++){
        int is_found =0;
        for(int j =0;j<size_set2;j++){
            if(set1[i]==set2[j]) {
                is_found = 1;
                break;
            }
        }
        if(is_found){
            set_intersection[amount_elements] = set1[i];
            amount_elements++;
        }
    }
    return amount_elements;
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

void phi_from_not_U_func(){

    int U[10] = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};

    int A[5] = {3, 4, 5, 6, 10};

    int B[5] = {1, 2, 3, 7, 9};

    int C[5] = {3, 4, 5, 8, 10};

    int result1[10]; // Максимально возможный размер, так как пересечение не будет больше U
    int n_res1 = unordered_array_set_intersection(U, 10, A, 5, result1);

    int result2[10]; // Максимально возможный размер
    int n_res2 = unordered_array_set_complement(result1, n_res1, U, 10, result2);

    int result3[10]; // Максимально возможный размер
    int n_res3 = unordered_array_set_complement(B, 5, U, 10, result3);

    int result4[10]; // Максимально возможный размер
    int n_res4 = unordered_array_set_intersection(U, 10, result3, n_res3, result4);

    int result5[10]; // Максимально возможный размер
    int n_res5 = unordered_array_set_difference(result2, n_res2, result4, n_res4, result5);

    int result6[10]; // Максимально возможный размер
    int n_res6 = unordered_array_set_intersection(C, 5, U, 10, result6);

    int result7[10]; // Максимально возможный размер
    int n_res7 = unordered_array_set_complement(result6, n_res6, U, 10, result7);


    int result8[10]; // Максимально возможный размер
    int n_res8 = unordered_array_set_intersection(result7, n_res7, A, 5, result8);

    int result9[10]; // Максимально возможный размер
    int n_res9 = unordered_array_set_union(result8, n_res8, B, 5, result9);

    int result10[10]; // Максимально возможный размер
    int n_res10 = unordered_array_set_symmetric_difference(result5, n_res5, result9, n_res9, result10);

    int result11[10];
    int n_res11 = unordered_array_set_complement(result10, n_res10, U, 10, result11);

    array_output(result11, n_res11);
}

void phi_from_empty_func(){

    int U[10] = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};

    int empty[0] = {};

    int A[5] = {3, 4, 5, 6, 10};

    int B[5] = {1, 2, 3, 7, 9};

    int C[5] = {3, 4, 5, 8, 10};

    int result1[0]; // Максимально возможный размер, так как пересечение с пустым множеством
    int n_res1 = unordered_array_set_intersection(empty, 0, A, 5, result1);

    int result2[10]; // Максимально возможный размер
    int n_res2 = unordered_array_set_complement(result1, n_res1, U, 10, result2);

    int result3[10]; // Максимально возможный размер
    int n_res3 = unordered_array_set_complement(B, 5, U, 10, result3);

    int result4[10]; // Максимально возможный размер
    int n_res4 = unordered_array_set_intersection(empty, 0, result3, n_res3, result4);

    int result5[10]; // Максимально возможный размер
    int n_res5 = unordered_array_set_difference(result2, n_res2, result4, n_res4, result5);

    int result6[10]; // Максимально возможный размер
    int n_res6 = unordered_array_set_intersection(C, 5, empty, 0, result6);

    int result7[10]; // Максимально возможный размер
    int n_res7 = unordered_array_set_complement(result6, n_res6, U, 10, result7);

    int result8[10]; // Максимально возможный размер
    int n_res8 = unordered_array_set_intersection(result7, n_res7, A, 5, result8);

    int result9[10]; // Максимально возможный размер
    int n_res9 = unordered_array_set_union(result8, n_res8, B, 5, result9);

    int result10[10]; // Максимально возможный размер
    int n_res10 = unordered_array_set_symmetric_difference(result5, n_res5, result9, n_res9, result10);

    array_output(result10, n_res10);
}

int main() {

    phi_from_empty_func();

    phi_from_not_U_func();

}
