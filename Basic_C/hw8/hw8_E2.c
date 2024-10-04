//Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.

#include <stdio.h>

#define ARRAY_SIZE 5

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int find_min(int array[], int arr_size)
{
    int min = array[0];
    for (int i = 0; i < arr_size; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }
    return min;
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    int min = find_min(array, ARRAY_SIZE);
    printf("%d\n", min);
    return 0;
}