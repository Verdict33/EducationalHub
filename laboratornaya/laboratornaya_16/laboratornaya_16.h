#include "../../libs/data_structures/matrix/matrix.h"

/*
1. Дана квадратная матрица, все элементы которой различны. Поменять местами
 строки, в которых находятся максимальный и минимальный элементы
*/
void exercise_1(matrix m);


/*
2. Упорядочить строки матрицы по неубыванию наибольших элементов строк

 Дополнительные функции:
 (a) int getMax(int *a, int n)
*/
void exercise_2(matrix m);


/*
3. Дана прямоугольная матрица. Упорядочить столбцы матрицы по неубыванию
минимальных элементов столбцов

 Дополнительные функции:
 (a) int getMin(int *a, int n)
*/
void exercise_3(matrix m);


/*
 4. Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом (𝐴^2)
 */
void exercise_4(matrix m);


/*
 5. Дана квадратная матрица. Если среди сумм элементов строк матрицы нет равных,
 то транспонировать матрицу
 */
void exercise_5(matrix m);


/*
 6. Даны две квадратные матрицы 𝐴 и 𝐵. Определить, являются ли они взаимно
обратными (𝐴 = 𝐵^(−1))
 */
int exercise_6(matrix m1, matrix m2);


/*
 7. Дана прямоугольная матрица. Назовем псевдодиагональю множество элементов этой матрицы, лежащих на прямой,
 параллельной прямой, содержащей элементы 𝑎𝑖,𝑖. Найти сумму максимальных элементов всех псевдодиагоналей
 данной матрицы

  Дополнительные функции:
 (a) int max(int a, int b)
 (b) long long findSumOfMaxesOfPseudoDiagonal(matrix m)
 */
void exercise_7(matrix m);


/*
 8. Дана прямоугольная матрица, все элементы которой различны. Найти минимальный элемент матрицы в выделенной области

 Дополнительные функции:
 (a) int getMinInArea(matrix m)
 */
void exercise_8(matrix m);


/*
 9. Дано 𝑛 точек в 𝑚-мерном пространстве. Упорядочить точки по неубыванию их расстояний до начала координат

 Дополнительные функции:
 (a) float getDistance(int *a, int n)
 (b) void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int))
 (с) void sortByDistances(matrix m)
 */
void exercise_9(matrix m);


/*
 10. Определить количество классов эквивалентных строк данной прямоугольной
матрицы. Строки считать эквивалентными, если равны суммы их элементов

 Дополнительные функции:
 (a) int cmp_long_long(const void *pa, const void *pb)
 (b) int countNUnique(long long *a, int n)
 (c) int countEqClassesByRowsSum(matrix m)
 */
void exercise_10(matrix m);


/*
 11. Дана матрица. Определить 𝑘 – количество "особых" элементов матрицы, считая
элемент "особым" , если он больше суммы остальных элементов своего столбца

 Дополнительные функции:
 (a) int getNSpecialElement(matrix m)
 */
void exercise_11(matrix m);


/*
 12. Дана квадратная матрица. Заменить предпоследнюю строку матрицы первым
из столбцов, в котором находится минимальный элемент матрицы.

 Дополнительные функции:
 (a) position getLeftMin(matrix m)
 (b) void swapPenultimateRow(matrix m, int n)
 */
void exercise_12(matrix m);


/*
 13. Дан массив матриц одного размера. Определить число матриц, строки которых упорядочены по неубыванию элементов

 Дополнительные функции:
 (a) bool isNonDescendingSorted(int *a, int n)
 (b) bool hasAllNonDescendingRows(matrix m)
 (c) int countNonDescendingRowsMatrices(matrix *ms, int nMatrix)
 */
void exercise_13(matrix m);


/*
 14. Дан массив целочисленных матриц. Вывести матрицы, имеющие наибольшее число нулевых строк

 Дополнительные функции:
 (a) int countValues(const int *a, int n, int value)
 (b) int countZeroRows(matrix m)
 (c) void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix)
 */
void exercise_14(matrix m);


/*
 15. Дан массив целочисленных квадратных матриц. Вывести матрицы с наименьшей нормой.
 В качестве нормы матрицы взять максимум абсолютных величин ее элементов
 */
void exercise_15(matrix m);


/*
 16. *Дана матрица. Определить 𝑘 – количество "особых" элементов данной матрицы, считая элемент "особым"
 если в строке слева от него находятся только меньшие элементы, а справа – только бoльшие

 Дополнительные функции:
 (a) int min2(int a, int b)
 (b) int getNSpecialElement2(matrix m)
 */
void exercise_16(matrix m);


/*
 17. *Каждая строка данной матрицы представляет собой координаты вектора в пространстве.
 Определить, какой из этих векторов образует максимальный угол  с данным вектором v

 Дополнительные функции:
 (a) double getScalarProduct(int *a, int *b, int n)
 (b) double getVectorLength(int *a, int n)
 (c) double getCosine(int *a, int *b, int n)
 (d) int getVectorIndexWithMaxAngle(matrix m, int *b)
 */
void exercise_17(matrix m);


/*
 18. *Дана целочисленная квадратная матрица, все элементы которой различны. Найти скалярное произведение
 строки, в которой находится наибольший элемент матрицы, на столбец с наименьшим элементом

 Дополнительные функции:
 (a) long long getScalarProductRowAndCol(matrix m, int i, int j)
 (b) long long getSpecialScalarProduct(matrix m, int n)
 */
void exercise_18(matrix m);