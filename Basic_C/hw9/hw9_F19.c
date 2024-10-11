//Определить количество положительных элементов квадратной матрицы, 
//превышающих по величине среднее арифметическое всех элементов главной диагонали. 
//Реализовать функцию среднее арифметическое главной диагонали.

#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE 5

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

float diag_avg(int size, int array[size][size])
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i][i];
    }

    float avg = sum / size;
    return avg;
}

int count_positive_bigger_than_avg(int size, int array[size][size])
{
    int counter = 0;
    float avg = diag_avg(size, array);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[j][i] > 0 && array[j][i] > avg)
            {
                counter++;
            }
        }
    }

    return counter;
}

int main(void)
{
    int array[ARRAY_SIZE][ARRAY_SIZE];
    read_matrix(ARRAY_SIZE, array);
    int count = count_positive_bigger_than_avg(ARRAY_SIZE, array);
    printf("%d\n", count);

    return 0;
}