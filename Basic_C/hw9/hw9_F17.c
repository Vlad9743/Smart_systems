//Составить функцию которая находит след матрицы в двумерном массиве.
//Показать пример ее работы на матрице из 5 на 5 элементов. След матрицы - это сумма элементов на главной диагонали.

#include <stdio.h>

#define COLUMNS 5
#define ROWS 5

void read_2dim_array(int columns, int rows, int array[columns][rows])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%d", &array[j][i]);
        }
    }
}

void print_2dim_array(int columns, int rows, int array[columns][rows])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%3d ", array[j][i]);
        }
        printf("\n");
    }
}

int matrix_trace(int columns, int rows, int array[columns][rows])
{
    int trace = 0;
    for (int i = 0; i < columns; i++)
    {
        trace += array[i][i];
    }
    return trace;
}

int main(void)
{
    int array[COLUMNS][ROWS];
    read_2dim_array(COLUMNS, ROWS, array);
    //print_2dim_array(COLUMNS, ROWS, array);
    int trace = matrix_trace(COLUMNS, ROWS, array);
    printf("%d\n", trace);

    return 0;
}