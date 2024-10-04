//Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

#include <stdio.h>

#define ARRAY_SIZE 5

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

float array_middle(int array[], int arr_size)
{
    float middle = 0;
    for (int i = 0; i < arr_size; i++)
    {
        middle += array[i];
    }
    middle /= arr_size;
    return middle;
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    float middle = array_middle(array, ARRAY_SIZE);
    printf("%.3f\n", middle);
    return 0;
}