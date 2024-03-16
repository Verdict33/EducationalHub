#include "matrix.h"

matrix matrix_get_mem(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

matrix *matrices_get_mem_array(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = matrix_get_mem(nRows, nCols);
    return ms;
}

void matrix_free_mem(matrix *m){
    for (int i = 0; i < m->nRows; ++i) {
        free(m->values[i]);
    }

    free(m->values);
}

void matrices_free_mem(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i) {
        matrix_free_mem(&ms[i]);
    }

    free(ms);
}

void matrix_input(matrix *m){
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            scanf("%d", &m->values[i][j]);
        }
    }
}

void matrices_input(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i) {
        matrix_input(&ms[i]);
    }
}

void matrix_output(matrix m){
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            printf("%d", m.values[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrices_output(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i) {
        matrix_output(ms[i]);
    }
}

void matrix_swap_rows(matrix m, int i1, int i2){
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void matrix_swap_columns(matrix m, int j1, int j2){
    for(int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j2];
        m.values[i][j2] = m.values[i][j1];
        m.values[i][j1] = temp;
    }
}

void matrix_insertion_sort_rows_by_row_criteria(matrix m, int (*criteria)(int*, int)){
    for (int i = 0; i < m.nRows - 1; ++i) {

        int min1 = criteria(m.values[i], m.nCols);
        int isTrue = i;

        for (int j = 1; j < m.nRows; ++j) {

            int min2 = criteria(m.values[j], m.nCols);
            if (min2 < min1)
                isTrue = j;
        }

        if (isTrue != i)
            matrix_swap_rows(m, i, isTrue);
    }
}

void matrix_selection_sort_cols_by_col_criteria(matrix m, int (*criteria)(int*, int)){
    for(int i = 0; i < m.nCols - 1; ++i){

        int isTrue = i;
        int a[m.nRows];

        for(int j = 0; j < m.nRows; ++j)
            a[j] = m.values[j][i];

        for(int j = 1; j < m.nCols; ++j){
            int b[m.nRows];

            for(int k = 0; k < m.nRows; ++k)
                b[k] = m.values[k][j];

            if(criteria(a, m.nRows) > criteria(b, m.nRows)) {
                isTrue = j;

                for(int l = 0; l < m.nRows; ++l)
                    a[l] = b[l];
            }
        }

        if(isTrue != i)
            matrix_swap_columns(m, i, isTrue);
    }
}

bool matrix_isSquare(matrix *m){
    return (m->nRows == m->nCols);
}

bool matrices_two_areEqual(matrix *m1, matrix *m2){
    if(m1->nRows != m2->nRows || m1->nCols != m2->nCols)
        return 0;

    for(int i = 0; i < m1->nRows; ++i){

        for(int j = 0; j < m1->nCols; ++j){

            if(m1->values[i][j] != m2->values[i][j])

                return 0;
        }
    }

    return 1;
}

bool matrix_isE(matrix *m){
    if(!matrix_isSquare(m))
        return 0;

    for(int i = 0; i < m->nRows; ++i){

        for(int j = 0; j < m->nCols; ++j){

            if(i != j && m->values[i][j] != 0)
                return 0;
        }

        if(m->values[i][i] != 1)
            return 0;
    }

    return 1;
}

bool matrix_isSymmetric(matrix *m){
    if(!matrix_isSquare(m))
        return 0;

    for(int i = 0; i < m->nCols; ++i){

        for(int j = 0; j < m->nRows; ++j){

            if(m->values[i][j] != m->values[j][i])
                return 0;
        }
    }

    return 1;
}

void matrix_transpose_square(matrix *m){
    if(matrix_isSquare(m)){

        for(int i = 0; i < m->nCols; ++i){

            for(int j = i + 1; j < m->nRows; ++j){

                int temp = m->values[i][j];
                m->values[i][j] = m->values[j][i];
                m->values[j][i] = temp;
            }
        }
    }
}

void matrix_transpose(matrix *m){
    int **t_matrix = (int **)malloc(m->nCols * sizeof(int *));

    for (int i = 0; i < m->nCols; i++)
        t_matrix[i] = (int *)malloc(m->nRows * sizeof(int));

    for (int i = 0; i < m->nRows; i++) {

        for (int j = 0; j < m->nCols; j++)
            t_matrix[j][i] = m->values[i][j];

    }

    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);

    free(m->values);

    m->values = t_matrix;

    int temp = m->nRows;
    m->nRows = m->nCols;
    m->nCols = temp;
}

position matrix_get_min_value_pos(matrix m){

    int row_index = 0;
    int col_index = 0;
    int min = m.values[0][0];

    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++){
            if(min > m.values[i][j]){

                min = m.values[i][j];
                row_index = i;
                col_index = j;
            }
        }
    }

    return (position){row_index, col_index};
}

position matrix_get_max_value_pos(matrix m){
    int row_index = 0;
    int col_index = 0;
    int max = m.values[0][0];

    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++){
            if(max < m.values[i][j]){

                max = m.values[i][j];
                row_index = i;
                col_index = j;
            }
        }
    }

    return (position){row_index, col_index};
}

matrix matrix_create_from_array(const int *a, size_t nRows, size_t nCols) {
    matrix m = matrix_get_mem(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

matrix *matrix_create_array_of_matrix_from_array(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = matrices_get_mem_array(nMatrices, nRows, nCols);

    int l = 0;

    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;
}

