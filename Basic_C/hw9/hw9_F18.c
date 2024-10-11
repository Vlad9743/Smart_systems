//Дана целочисленная квадратная матрица 10 х 10.
//реализовать алгоритм вычисления суммы максимальных элементов из каждой строки.
//Напечатать значение этой суммы.
//Предполагается, что в каждой строке такой элемент единственный. Реализовать функцию поиска максимума в строке из 10 элементов

#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE 10

void read_matrix(int size, int array[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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

int sum_max_in_strings(int size, int array[size][size])
{
    int sum_max = 0;
    for (int i = 0; i < size; i++)
    {
        int local_max = INT_MIN;
        for (int j = 0; j < size; j++)
        {
            if (array[j][i] > local_max)
            {
                local_max = array[j][i];
            }
        }
        sum_max += local_max;
    }
    return sum_max;
}

int main(void)
{
    int array[ARRAY_SIZE][ARRAY_SIZE];
    read_matrix(ARRAY_SIZE, array);
    //print_2dim_array(ARRAY_SIZE, ARRAY_SIZE, array);
    int sum = sum_max_in_strings(ARRAY_SIZE, array);
    printf("%d\n", sum);
    return 0;
}