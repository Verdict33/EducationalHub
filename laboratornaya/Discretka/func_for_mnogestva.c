//Включение
//#include <stdio.h>
//#include <stdbool.h>
//#include "libs/algorithms/array/array.h"
//bool unordered_array_set_isEqual(int *set, size_t n_set, int *subset, size_t
//n_subset) {
//    if (n_set < n_subset)
//        return false;
//    for (int i = 0; i < n_subset; i++) {
//        int is_equal = 0;
//        for (int j = 0; j < n_set; j++) {
//            if (subset[i] == set[j]) {
//                is_equal = 1;
//                break;
//            }
//        }
//        if (!is_equal)
//            return false;
//    }
//    return true;
//}
//int main() {
//    int n_a, n_b;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    printf("%d", unordered_array_set_isEqual(a, n_a, b, n_b));
//}
//Строгое включение
//#include <stdio.h>
//#include <stdbool.h>
//#include "libs/algorithms/array/array.h"
//bool unordered_array_set_isSubset(int *set, size_t n_set, int *subset, size_t
//n_subset) {
//    if (n_set <= n_subset)
//        return false;
//    for (int i = 0; i < n_subset; i++) {
//        int is_unical = 0;
//        for (int j = 0; j < n_set; j++) {
//            if (subset[i] == set[j]) {
//                is_unical = 1;
//                break;
//            }
//        }
//        if (!is_unical)
//            return false;
//    }
//    return true;
//}
//int main() {
//    int n_a, n_b;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    printf("%d", unordered_array_set_isSubset(a, n_a, b, n_b));
//}
//Объединение
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//        size_t unordered_array_set_union(int *set, size_t n_set, int *subset, size_t
//n_subset, int *set_result){
//    size_t n_set_result = 0;
//    for(int i = 0; i < n_set; i++)
//        set_result[n_set_result++] = set[i];
//    for(int i = 0; i < n_subset; i++){
//        int is_union = 1;
//        for(int j = 0; j < n_set_result; j++){
//            if(subset[i] == set_result[j]){
//                is_union = 0;
//                break;
//            }
//        }
//        if(is_union)
//            set_result[n_set_result++] = subset[i];
//    }
//    return n_set_result;
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    n_c = unordered_array_set_union(a, n_a, b, n_b, c);
//    outputArray_(c, n_c);
//}
//Пересечение
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//int unordered_array_set_intersection(int *set1, int *set2, int
//*set_intersection, size_t size_set1, size_t size_set2) {
//    int amount_elements = 0;
//    for(int i= 0; i<size_set1;i++){
//        int is_found =0;
//        for(int j =0;j<size_set2;j++){
//            if(set1[i]==set2[j]) {
//                is_found = 1;
//                break;
//            }
//        }
//        if(is_found){
//            set_intersection[amount_elements] = set1[i];
//            amount_elements++;
//        }
//    }
//    return amount_elements;
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    n_c = unordered_array_set_intersection(a, n_a, b, n_b, c);
//    outputArray_(c, n_c);
//}
//Разность
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//        size_t unordered_array_set_difference(int *set1, size_t n_set1, int *set2,
//                                              size_t n_set2, int *set_result) {
//    int n_set_result = 0;
//    for (int i = 0; i < n_set1; i++) {
//        int found = 0;
//        for (int j = 0; j < n_set2; j++) {
//            if (set1[i] == set2[j]) {
//                found = 1;
//                break;
//            }
//        }
//        if (!found) {
//            set_result[n_set_result] = set1[i];
//            n_set_result++;
//        }
//    }
//    return n_set_result;
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    n_c = unordered_array_set_difference(a, n_a, b, n_b, c);
//    outputArray_(c, n_c);
//}
//Симметрическая разность
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//size_t unordered_array_set_union(int *set, size_t n_set, int *subset, size_t
//n_subset, int *set_result){
//    size_t n_set_result = 0;
//    for(int i = 0; i < n_set; i++)
//        set_result[n_set_result++] = set[i];
//    for(int i = 0; i < n_subset; i++){
//        int is_union = 1;
//        for(int j = 0; j < n_set_result; j++){
//            if(subset[i] == set_result[j]){
//                is_union = 0;
//                break;
//            }
//        }
//        if(is_union)
//            set_result[n_set_result++] = subset[i];
//    }
//    return n_set_result;
//}
//size_t unordered_array_set_difference(int *set1, size_t n_set1, int *set2,
//                                      size_t n_set2, int *set_result) {
//    int n_set_result = 0;
//    for (int i = 0; i < n_set1; i++) {
//        int found = 0;
//        for (int j = 0; j < n_set2; j++) {
//            if (set1[i] == set2[j]) {
//                found = 1;
//                break;
//            }
//        }
//        if (!found) {
//            set_result[n_set_result] = set1[i];
//            n_set_result++;
//        }
//    }
//    return n_set_result;
//}
//int unordered_array_set_symmetric_difference(int *set1, size_t n_set1, int
//*set2, size_t n_set2, int *result) {
//    int temp_set_1[n_set1 + n_set2];
//    int temp_set_2[n_set1 + n_set2];
//    int first_difference = unordered_array_set_difference(set1, n_set1, set2,
//                                                          n_set2, temp_set_1);
//    int second_difference = unordered_array_set_difference(set2, n_set2,
//                                                           set1, n_set1, temp_set_2);
//    int necessary_elements =
//            unordered_array_set_union(temp_set_1,first_difference,temp_set_2,second_diffe
//    rence,result);
//    return necessary_elements;
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    n_c = unordered_array_set_symmetric_difference(a, n_a, b, n_b, c);
//    outputArray_(c, n_c);
//}
//Дополнение до универсума
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//        size_t unordered_array_set_difference(int *set1, size_t n_set1, int *set2,
//                                              size_t n_set2, int *set_result) {
//    int n_set_result = 0;
//    for (int i = 0; i < n_set1; i++) {
//        int found = 0;
//        for (int j = 0; j < n_set2; j++) {
//            if (set1[i] == set2[j]) {
//                found = 1;
//                break;
//            }
//        }
//        if (!found) {
//            set_result[n_set_result] = set1[i];
//            n_set_result++;
//        }
//    }
//    return n_set_result;
//}
//size_t unordered_array_set_complement(int *set, size_t n_set, int *comp,
//                                      size_t n_comp, int *set_result){
//    size_t n_set_result = unordered_array_set_difference(comp, n_comp, set,
//                                                         n_set, set_result);
//    return n_set_result;
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    n_c = unordered_array_set_complement(a, n_a, b, n_b, c);
//    outputArray_(c, n_c);
//}
//б) элементы множества А хранятся в массиве А. Элементы массива А
//        упорядочены по возрастанию.
//Включение
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//#include <stdbool.h>
//bool ordered_array_set_isEqual(int *set, size_t n_set, int *subset, size_t
//n_subset) {
//    if (n_set < n_subset)
//        return false;
//    int index_set = 0, index_subset = 0, is_equal = 0;
//    while (index_set < n_set && index_subset < n_subset){
//        if(set[index_set] == subset[index_subset]){
//            is_equal = 1;
//            index_set++;
//            index_subset++;
//        }
//        else{
//            is_equal = 0;
//            index_set++;
//        }
//    }
//    if(!is_equal)
//        return false;
//    return true;
//}
//int main() {
//    int n_a, n_b;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    printf("%d", ordered_array_set_isEqual(a, n_a, b, n_b));
//}
//Строгое включение
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//#include <stdbool.h>
//bool ordered_array_set_isSubset(int *set, size_t n_set, int *subset, size_t
//n_subset) {
//    if (n_set <= n_subset)
//        return false;
//    int index_set = 0, index_subset = 0, is_equal = 0;
//    while (index_set < n_set && index_subset < n_subset){
//        if(set[index_set] == subset[index_subset]){
//            is_equal = 1;
//            index_set++;
//            index_subset++;
//        }
//        else{
//            is_equal = 0;
//            index_set++;
//        }
//    }
//    if(!is_equal)
//        return false;
//    return true;
//}
//int main() {
//    int n_a, n_b;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    printf("%d", ordered_array_set_isSubset(a, n_a, b, n_b));
//}
//Объединение
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//void ordered_array_set_union(const int *set1, int n_set1, const int *set2,
//                             int n_set2, int *set_result, int *n_set_result) {
//    int index_set1 = 0, index_set2 = 0, necessary_elements = 0;
//    while (index_set1 < n_set1 && index_set2 < n_set2) {
//        if (set1[index_set1] < set2[index_set2]) {
//            set_result[necessary_elements++] = set1[index_set1++];
//        } else if (set1[index_set1] > set2[index_set2]) {
//            set_result[necessary_elements++] = set2[index_set2++];
//        } else {
//            set_result[necessary_elements++] = set1[index_set1++];
//            index_set2++;
//        }
//    }
//    while (index_set1 < n_set1) {
//        set_result[necessary_elements++] = set1[index_set1++];
//    }
//    while (index_set2 < n_set2) {
//        set_result[necessary_elements++] = set2[index_set2++];
//    }
//    *n_set_result = necessary_elements;
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    ordered_array_set_union(a, n_a, b, n_b, c, &n_c);
//    outputArray_(c, n_c);
//}
//Пересечение
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//int ordered_array_set_intersection(int *set1, size_t n_set1, int *set2,
//                                   size_t n_set2, int *set_result) {
//    int index_set1 = 0, index_set2 = 0, necessary_elements = 0;
//    while (index_set1 < n_set1 && index_set2 < n_set2) {
//        if (set1[index_set1] == set2[index_set2]) {
//            set_result[necessary_elements++] = set1[index_set1];
//            index_set1++;
//            index_set2++;
//        } else if (set1[index_set1] < set2[index_set2]) {
//            index_set1++;
//        } else {
//            index_set2++;
//        }
//    }
//    return necessary_elements;
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    n_c = ordered_array_set_intersection(a, n_a, b, n_b, c);
//    outputArray_(c, n_c);
//}
//Разность
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//int ordered_array_set_difference(int *set1, size_t n_set1, int *set2, size_t
//n_set2, int *set_result) {
//    int index_set1 = 0, index_set2 = 0, necessary_elements = 0;
//    while (index_set1 < n_set1 && index_set2 < n_set2) {
//        if (set1[index_set1] == set2[index_set2]) {
//            index_set1++;
//            index_set2++;
//        } else if (set1[index_set1] < set2[index_set2]) {
//            set_result[necessary_elements++] = set1[index_set1++];
//        } else {
//            index_set2++;
//        }
//    }
//    while (index_set1 < n_set1) {
//        set_result[necessary_elements++] = set1[index_set1++];
//    }
//    return necessary_elements;
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    n_c = ordered_array_set_difference(a, n_a, b, n_b, c);
//    outputArray_(c, n_c);
//}
//Симметрическая разность
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//int ordered_array_set_difference(int *set1, size_t n_set1, int *set2, size_t
//n_set2, int *set_result) {
//    int index_set1 = 0, index_set2 = 0, necessary_elements = 0;
//    while (index_set1 < n_set1 && index_set2 < n_set2) {
//        if (set1[index_set1] == set2[index_set2]) {
//            index_set1++;
//            index_set2++;
//        } else if (set1[index_set1] < set2[index_set2]) {
//            set_result[necessary_elements++] = set1[index_set1++];
//        } else {
//            index_set2++;
//        }
//    }
//    while (index_set1 < n_set1) {
//        set_result[necessary_elements++] = set1[index_set1++];
//    }
//    return necessary_elements;
//}
//void ordered_array_set_union(const int *set1, int n_set1, const int *set2,
//                             int n_set2, int *set_result, int *n_set_result) {
//    int index_set1 = 0, index_set2 = 0, necessary_elements = 0;
//    while (index_set1 < n_set1 && index_set2 < n_set2) {
//        if (set1[index_set1] < set2[index_set2]) {
//            set_result[necessary_elements++] = set1[index_set1++];
//        } else if (set1[index_set1] > set2[index_set2]) {
//            set_result[necessary_elements++] = set2[index_set2++];
//        } else {
//            set_result[necessary_elements++] = set1[index_set1++];
//            index_set2++;
//        }
//    }
//    while (index_set1 < n_set1) {
//        set_result[necessary_elements++] = set1[index_set1++];
//    }
//    while (index_set2 < n_set2) {
//        set_result[necessary_elements++] = set2[index_set2++];
//    }
//    *n_set_result = necessary_elements;
//}
//int unordered_array_set_symmetric_difference(int *set1, size_t n_set1, int
//*set2, size_t n_set2, int *result, int *n_result) {
//    int temp_set_1[n_set1 + n_set2];
//    int temp_set_2[n_set1 + n_set2];
//    int first_difference = ordered_array_set_difference(set1, n_set1, set2,
//                                                        n_set2, temp_set_1);
//    int second_difference = ordered_array_set_difference(set2, n_set2, set1,
//                                                         n_set1, temp_set_2);
//
//    ordered_array_set_union(temp_set_1,first_difference,temp_set_2,second_differe
//    nce,result, n_result);
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    unordered_array_set_symmetric_difference(a, n_a, b, n_b, c, &n_c);
//    outputArray_(c, n_c);
//}
//Дополнение до универсума
//#include <stdio.h>
//#include "libs/algorithms/array/array.h"
//int ordered_array_set_difference(int *set1, size_t n_set1, int *set2, size_t
//n_set2, int *set_result) {
//    int index_set1 = 0, index_set2 = 0, necessary_elements = 0;
//    while (index_set1 < n_set1 && index_set2 < n_set2) {
//        if (set1[index_set1] == set2[index_set2]) {
//            index_set1++;
//            index_set2++;
//        } else if (set1[index_set1] < set2[index_set2]) {
//            set_result[necessary_elements++] = set1[index_set1++];
//        } else {
//            index_set2++;
//        }
//    }
//    while (index_set1 < n_set1) {
//        set_result[necessary_elements++] = set1[index_set1++];
//    }
//    return necessary_elements;
//}
//size_t ordered_array_set_complement(int *set, size_t n_set, int *comp, size_t
//n_comp, int *set_result){
//    size_t n_set_result = ordered_array_set_difference(comp, n_comp, set,
//                                                       n_set, set_result);
//    return n_set_result;
//}
//int main() {
//    int n_a, n_b, n_c;
//    scanf("%d %d", &n_a, &n_b);
//    int a[n_a];
//    inputArray_(a, n_a);
//    int b[n_b];
//    inputArray_(b, n_b);
//    int c[n_c];
//    n_c = ordered_array_set_complement(a, n_a, b, n_b, c);
//    outputArray_(c, n_c);
//}
//в) элементы множества А хранятся в массиве А, элементы которого типа
//        boolean. Если i∈A, то Аi=true, иначе Ai=false.
//        Включение
//#include <stdio.h>
//#include <stdbool.h>
//bool isIncluded(const bool *set1, const bool *set2, int size_universum) {
//    for (int i = 0; i < size_universum; i++) {
//        if (set1[i] && !set2[i])
//            return false;
//    }
//    return true;
//}
//int main() {
//    bool a[6] = {true, true, true, true, true,true};
//    bool b[4] = {true, true, true, true};
//    printf("%d", isIncluded(a, b, 6));
//}
//Объединение
//#include <stdio.h>
//#include <stdbool.h>
//void outputArray(const bool *a, const size_t n) {
//    for (size_t i = 0; i < n; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//}
//void bool_union(bool *set1, bool *set2, bool *set_universum, size_t
//n_universum){
//    for(int i = 0; i < n_universum; i++){
//        set_universum[i] = set1[i] || set2[i];
//    }
//}
//int main() {
//    bool a[5] = {false,true,false,true,true};
//    bool b[5] = {false, false, false,true,true};
//    bool c[5];
//    bool_union(a, b, c,5);
//    outputArray(c, 5);
//}
//Пересечение
//#include <stdio.h>
//#include <stdbool.h>
//void outputArray(const bool *a, const size_t n) {
//    for (size_t i = 0; i < n; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//}
//void bool_intersection(bool *set1, bool *set2, bool *set_intersection, size_t
//n_universum){
//    for(int i = 0; i < n_universum; i++){
//        set_intersection[i] = set1[i] && set2[i];
//    }
//}
//int main() {
//    bool a[4] = {false,true,false,true};
//    bool b[4] = {false, true, true,false};
//    bool c[4];
//    bool_intersection(a, b, c,4);
//    outputArray(c, 4);
//}
//Разность
//#include <stdio.h>
//#include <stdbool.h>
//void outputArray(const bool *a, const size_t n) {
//    for (size_t i = 0; i < n; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//}
//void bool_difference(bool *set1, bool *set2, bool *set_difference, size_t
//n_universum){
//    for(int i = 0; i < n_universum; i++){
//        set_difference[i] = set1[i] && (!set2[i]);
//    }
//}
//int main() {
//    bool a[4] = {false,true,false,true};
//    bool b[4] = {false, true, true,false};
//    bool c[4];
//    bool_difference(a, b, c,4);
//    outputArray(c, 4);
//}
//Симметрическая разность
//#include <stdio.h>
//#include <stdbool.h>
//void outputArray(const bool *a, const size_t n) {
//    for (size_t i = 0; i < n; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//}
//void bool_symmetric_difference(bool *set1, bool *set2, bool
//*set_symmetric_difference, size_t n_universum) {
//    for (int i = 0; i < n_universum; i++) {
//        if (set1[i] == set2[i])
//            set_symmetric_difference[i] = false;
//        else
//            set_symmetric_difference[i] = set1[i] || set2[i];
//    }
//}
//int main() {
//    bool a[4] = {false,true,false,true};
//    bool b[4] = {false, true, true,false};
//    bool c[4];
//    bool_symmetric_difference(a, b, c,4);
//    outputArray(c, 4);
//}
//Дополнение до универсума
//#include <stdio.h>
//#include <stdbool.h>
//void outputArray(const bool *a, const size_t n) {
//    for (size_t i = 0; i < n; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//}
//void bool_complement(bool *set, bool *set_universum, bool *set_complement,
//                     size_t n_universum){
//    for(int i = 0; i < n_universum; i++){
//        set_complement[i] = set_universum[i] && (!set[i]);
//    }
//}
//int main() {
//    bool a[4] = {false,true,false,true};
//    bool b[4] = {false, true, true,false};
//    bool c[4];
//    bool_complement(a, b, c,4);
//    outputArray