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



matrix mulMatrices(matrix m1, matrix m2){

}

void getSquareOfMatrixIfSymmetric(matrix *m){

}

void exercise_4(){

}



bool isUnique(long long *a, int n){

}

long long getSum(int *a, int n){

}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m){

}

void exercise_5(){

}



bool isMutuallyInverseMatrices(matrix m1, matrix m2){

}

void exercise_6(){

}



int max(int a, int b){

}

long long findSumOfMaxesOfPseudoDiagonal(matrix m){

}

void exercise_7(){

}



int getMinInArea(matrix m){

}

void exercise_8(){

}



float getDistance(int *a, int n){

}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)){

}

void sortByDistances(matrix m){

}

void exercise_9(){

}



int cmp_long_long(const void *pa, const void *pb){

}

int countNUnique(long long *a, int n){

}

int countEqClassesByRowsSum(matrix m){

}

void exercise_10(){

}



int getNSpecialElement(matrix m){

}

void exercise_11(){

}



position getLeftMin(matrix m){

}

void swapPenultimateRow(matrix m, int n){

}

void exercise_12(){

}



bool isNonDescendingSorted(int *a, int n){

}

bool hasAllNonDescendingRows(matrix m){

}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix){

}

void exercise_13(){

}



int countValues(const int *a, int n, int value){

}

int countZeroRows(matrix m){

}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix){

}

void exercise_14(){

}



void exercise_15(){

}



int min2(int a, int b){

}

int getNSpecialElement2(matrix m){

}

void exercise_16(){

}



double getScalarProduct(int *a, int *b, int n){

}

double getVectorLength(int *a, int n){

}

double getCosine(int *a, int *b, int n){

}

int getVectorIndexWithMaxAngle(matrix m, int *b){

}

void exercise_17(){

}



long long getScalarProductRowAndCol(matrix m, int i, int j){

}

long long getSpecialScalarProduct(matrix m, int n){

}

void exercise_18(){

}