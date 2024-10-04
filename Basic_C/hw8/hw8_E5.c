//Считать массив из 10 элементов и посчитать сумму положительных элементов массива.

#include <stdio.h>

#define ARRAY_SIZE 10

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int sum_of_positives(int array[], int arr_size)
{
    int sum = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (array[i] > 0)
        {
            sum += array[i];
        }
    }
    return sum;
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    printf("%d\n", sum_of_positives(array, ARRAY_SIZE));
    return 0;
}