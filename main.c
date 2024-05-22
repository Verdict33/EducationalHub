#include <stdio.h>

#define nRows 5 // размеры решетки (Ввести вручную)
#define nCols 5

// Структура для хранения предыдущей точки
typedef struct {
    int x;
    int y;
} PrevPoint;

int main() {

    int cost[nRows][nCols] = {
            {3, 1, 1, 4, 8},
            {7, 5, 3, 3, 1},
            {7, 9, 6, 1, 2},
            {1, 4, 8, 4, 9},
            {8, 9, 4, 2, 11},
    };

    int step_price[nRows][nCols];
    PrevPoint prev_point[nRows][nCols]; // Матрица для хранения предыдущих точек
    int x, y;

    printf("Enter coordinates x, y: ");
    scanf("%d %d", &x, &y);

    // заполняем первую строку и первый столбец
    step_price[4][0] = cost[4][0];
    prev_point[4][0].x = 9;
    prev_point[4][0].y = 0;

    for (int i = nRows - 2; i >= 0; i--) {
        step_price[i][0] = step_price[i + 1][0] + cost[i][0];
        prev_point[i][0].x = i;
        prev_point[i][0].y = 0;
    }

    for (int j = 1; j < nCols; j++) {
        step_price[nRows - 1][j] = step_price[nRows - 1][j - 1] + cost[nRows - 1][j];
        prev_point[nRows - 1][j].x = nRows - 1;
        prev_point[nRows - 1][j].y = j - 1;
    }

    // заполняем массив step_price
    for (int i = nRows - 2; i >= 0; i--) {
        for (int j = 1; j < nCols; j++) {
            if (step_price[i + 1][j] < step_price[i][j - 1]) {
                step_price[i][j] = cost[i][j] + step_price[i + 1][j];
                prev_point[i][j].x = i + 1; // Исправление: здесь нужно записывать i+1, а не i
                prev_point[i][j].y = j;
            } else {
                step_price[i][j] = cost[i][j] + step_price[i][j - 1];
                prev_point[i][j].x = i;
                prev_point[i][j].y = j - 1;
            }
        }
    }

    printf("Min cost to reach point (%d, %d) is: %d\n", x, y, step_price[nRows - 1 - y][x]);

    // Вывод траектории
    int cur_x = x;
    int cur_y = nRows - 1 - y;
    printf("Trajectory: ");
    // Выводим целевую точку
    printf("(%d, %d) <- ", cur_x, cur_y);
    // Двигаемся назад по траектории
    while (cur_x != 0 || cur_y != 0) {
        // prev_point[cur_y][cur_x].x - хранит x-координату предыдущей точки
        // prev_point[cur_y][cur_x].y - хранит y-координату предыдущей точки
        cur_x = prev_point[cur_y][cur_x].x;
        cur_y = prev_point[cur_y][cur_x].y;
        printf("(%d, %d) <- ", cur_x, cur_y);
    }
    printf("(0, 0)\n");

    return 0;
}