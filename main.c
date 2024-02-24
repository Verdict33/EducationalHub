#include "libs/algorithms/array/array.h"

int ordered_array_set_difference(int *set1, size_t n_set1, int *set2, size_t n_set2, int *set_result) {

    int index_set1 = 0, index_set2 = 0, necessary_elements = 0;

    while (index_set1 < n_set1 && index_set2 < n_set2) {
        if (set1[index_set1] == set2[index_set2]) {
            index_set1++;
            index_set2++;
        } else if (set1[index_set1] < set2[index_set2]) {
            set_result[necessary_elements++] = set1[index_set1++];
        } else {
            index_set2++;
        }
    }
    while (index_set1 < n_set1) {
        set_result[necessary_elements++] = set1[index_set1++];
    }
    return necessary_elements;
}

void ordered_array_set_union(const int *set1, int n_set1, const int *set2, int n_set2, int *set_result, int *n_set_result) {

    int index_set1 = 0, index_set2 = 0, necessary_elements = 0;

    while (index_set1 < n_set1 && index_set2 < n_set2) {
        if (set1[index_set1] < set2[index_set2]) {
            set_result[necessary_elements++] = set1[index_set1++];
        } else if (set1[index_set1] > set2[index_set2]) {
            set_result[necessary_elements++] = set2[index_set2++];
        } else {
            set_result[necessary_elements++] = set1[index_set1++];
            index_set2++;
        }
    }
    while (index_set1 < n_set1) {
        set_result[necessary_elements++] = set1[index_set1++];
    }
    while (index_set2 < n_set2) {
        set_result[necessary_elements++] = set2[index_set2++];
    }
    *n_set_result = necessary_elements;
}



int unordered_array_set_symmetric_difference(int *set1, size_t n_set1, int *set2, size_t n_set2, int *result, int *n_result) {
    int temp_set_1[n_set1 + n_set2];
    int temp_set_2[n_set1 + n_set2];

    int first_difference = ordered_array_set_difference(set1, n_set1, set2, n_set2, temp_set_1);
    int second_difference = ordered_array_set_difference(set2, n_set2, set1, n_set1, temp_set_2);

    ordered_array_set_union(temp_set_1,first_difference,temp_set_2,second_difference,result, n_result);

}



int main() {

    int res_1[6] = {1, 3, 4, 7, 9, 10};
    int C[5] = {4, 7, 8, 11, 12};

    int n_res_2;
    int res_2[n_res_2];

    unordered_array_set_symmetric_difference(res_1, 6,C, 5,  res_2, &n_res_2);

    outputArray_(res_2, n_res_2);

}
