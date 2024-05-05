#include <stdio.h>
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
void print_set(int set[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}
void combinations(int phi_from_not_U[], int n_phi_from_not_U, int
phi_from_empty[], int n_phi_from_empty) {
    int n_set_result = n_phi_from_not_U + n_phi_from_empty;
    int set_result[n_set_result];
    for (int i = 0; i < (1 << n_phi_from_not_U); i++) {
        int index = 0;
        for (int j = 0; j < n_phi_from_not_U; j++) {
            if (i & (1 << j)) {
                set_result[index++] = phi_from_not_U[j];
            }
        }
        for (int j = 0; j < n_phi_from_empty; j++) {
            set_result[index++] = phi_from_empty[j];
        }
        print_set(set_result, index);
    }
}
int main() {
    int phi_from_not_U[2] = {1, 2};
    int phi_from_empty[0] = {};
    int dif_not_U_and_empty[10];
    int n_dif_not_U_and_empty = unordered_array_set_difference(phi_from_not_U, 2,
                                                               phi_from_empty, 0, dif_not_U_and_empty);
    combinations(dif_not_U_and_empty, n_dif_not_U_and_empty, phi_from_empty, 0);
    return 0;
}