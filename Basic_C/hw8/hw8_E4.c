//Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.

#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE 10

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int sum_of_two_max(int array[], int arr_size)
{
    int max1 = INT_MIN, max2 = INT_MIN;

    for (int i = 0; i < arr_size; i++)
    {
        if (max1 < array[i])
        {
            max2 = max1;
            max1 = array[i];
            continue;
        }
        if (max2 < array[i])
        {
            max2 = array[i];
        }
    }
/*
    for (int i = 0; i < arr_size; i++)
    {
        if (max2 < array[i] && array[i] < max1)
        {
            max2 = array[i];
        }
    }
*/
    return max1 + max2;
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    printf("%d\n", sum_of_two_max(array, ARRAY_SIZE));
    return 0;
}