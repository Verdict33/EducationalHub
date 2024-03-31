#include "array.h"


void array_input(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void array_output(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

size_t array_linearSearch(const int *a, const size_t n, int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}

size_t array_binarySearch(const int *a, size_t n, int x) {
    size_t left = 0;
    size_t right = n - 1;
    while (left <= right) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return SIZE_MAX;
}

size_t array_binarySearchMoreOrEqual(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;
    size_t left = 0;
    size_t right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }
    return right;
}

void array_insert(int *const a, size_t *const n, const size_t pos,
             const int value) {
    assert (pos < *n);
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;

        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        a[pos] = value;
    } else {
        (*n)++;
        a[pos] = value;
    }
}

void array_append(int *const a, size_t *const n, const int value) {
    a[*n] = value;
    (*n)++;
}

void array_deleteByPosSaveOrder(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void array_deleteByPosUnsaveOrder(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

int array_all(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (!predicate(a[i]))
            return 0;
    return 1;
}

int array_any(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (predicate(a[i]))
            return 1;
    return 0;
}

void array_forEach(const int *source, int *dest, const size_t n, const int (*
predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        dest[i] = predicate(source[i]);
}

int array_countIf(const int *const a, const size_t n, int (*predicate )(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);
    return count;
}

void array_deleteIf(int *const a, size_t *const n, int (*deletePredicate )(
        int)) {
    size_t iRead = 0;
    while (iRead < *n && !deletePredicate(a[iRead]))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (!deletePredicate(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;

        }
        iRead++;
    }
    *n = iWrite;
}

int array_compare_ints(const void *a, const void *b) {
    const int *num1 = (const int *) a;
    const int *num2 = (const int *) b;
    return *num1 - *num2;
}

bool array_elements_areUnigue(int *a, int n){
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(a[i] == a[j])
                return 0;
        }
    }
    return 1;
}

int array_count_unique_element(int *a, int n){
    int unique_element = 0;
    int is_start = 0;
    int is_end = 0;

    for (int i = 1; i < n - 1; ++i) {
        if(a[i] != a[i + 1] && a[i] != a[i - 1])
            unique_element++;

        if(is_start == 0 && a[0] != a[1]){
            unique_element++;
            is_start = 1;
        }

        if(is_end == 0 && a[n-1] != a[n]){
            unique_element++;
            is_end = 1;
        }
    }
    return unique_element;
}