#include "laboratornaya_16.h"

void exercise_1(matrix m){
    position min = matrix_get_min_value_pos(m);
    position max = matrix_get_max_value_pos(m);
    matrix_swap_rows(m, min.rowIndex, max.rowIndex);
}



int getMax(int *a, int n){
    int max = a[0];

    for (int i = 0; i < n; ++i) {
        if (max < a[i])
            max = a[i];
    }

    return max;
}

void exercise_2(matrix m){
    matrix_insertion_sort_rows_by_row_criteria(m, getMax);
}



int getMin(int *a, int n){
    int min = a[0];

    for (int i = 0; i < n; ++i) {
        if (min > a[i])
            min = a[i];
    }

    return min;
}

void exercise_3(matrix m){
    matrix_selection_sort_cols_by_col_criteria(m, getMin);
}



void exercise_4(matrix m){
    if(matrix_isSymmetric(&m) == 0){
        printf("This matrix is not symmetric");
        exit(1);

    } else{
        for (int i = 0; i < m.nRows; ++i) {
            for (int j = 0; j < m.nCols; ++j) {
                m.values[i][j] *= m.values[i][j];
            }
        }
    }
}



void exercise_5(matrix m){
    int sum_elements_row[m.nRows];

    for(int i = 0; i < m.nRows; i++){
        int sum = 0;

        for(int j = 0; j < m.nCols; j++)
            sum += m.values[i][j];

        sum_elements_row[i] = sum;
    }

    if(array_elements_areUnigue(sum_elements_row, m.nRows))
        matrix_transpose_square(&m);
}



int exercise_6(matrix m1, matrix m2){
    matrix result = matrix_square_multiplication(&m1, &m2);

    if (!matrix_isE(&result)) {
        matrix_free_mem(&result);
        return 0;

    } else {
        matrix_free_mem(&result);
        return 1;
    }
}



int max(int a, int b){

}

long long findSumOfMaxesOfPseudoDiagonal(matrix m){

}

void exercise_7(matrix m){

}



int getMinInArea(matrix m){

}

int exercise_8(matrix m) {
    position max = matrix_get_max_value_pos(m);
    int min = INT_MAX;

    for (int i = 0; i <= max.rowIndex; ++i) {
        int colum_off = (max.rowIndex - i) << 1;
        int column_on_start = MAX(0, max.colIndex - colum_off);
        int column_on_end = MIN((m.nCols - 1), max.colIndex + colum_off);

        for (int j = column_on_start; j < column_on_end; ++j) {
            min = MIN(min, m.values[i][j]);
        }
    }
    return min;
}


float getDistance(int *a, int n){

}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)){

}

void sortByDistances(matrix m){

}

void exercise_9(matrix m){

}



int exercise_10(matrix m){
    int sum = 0;
    int a[m.nRows];

    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++)
            sum += m.values[i][j];

        a[i] = sum;
        sum = 0;
    }

    bubbleSort(a, m.nRows);

    int equal_class = array_count_unique_element(a, m.nRows);;

    return equal_class;
}



int getNSpecialElement(matrix m){

}

void exercise_11(matrix m){

}



position getLeftMin(matrix m){

}

void swapPenultimateRow(matrix m, int n){

}

void exercise_12(matrix m){

}



bool isNonDescendingSorted(int *a, int n){

}

bool hasAllNonDescendingRows(matrix m){

}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix){

}

void exercise_13(matrix m){

}



int countValues(const int *a, int n, int value){

}

int countZeroRows(matrix m){

}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix){

}

void exercise_14(matrix m){

}



void exercise_15(matrix m){

}



int min2(int a, int b){

}

int getNSpecialElement2(matrix m){

}

void exercise_16(matrix m){

}



double getScalarProduct(int *a, int *b, int n){

}

double getVectorLength(int *a, int n){

}

double getCosine(int *a, int *b, int n){

}

int getVectorIndexWithMaxAngle(matrix m, int *b){

}

void exercise_17(matrix m){

}



long long getScalarProductRowAndCol(matrix m, int i, int j){

}

long long getSpecialScalarProduct(matrix m, int n){

}

void exercise_18(matrix m){

}