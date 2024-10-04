//Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.

#include <stdio.h>

#define ARRAY_SIZE 12

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void swap_elements(int *elem1, int *elem2)
{
    int temp;
    temp = *elem2;
    *elem2 = *elem1;
    *elem1 = temp;
}

void invers_thirds_and_print(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (i % 4 == 0)
        {
            swap_elements(array+i, array+i+3);
        }

        if ((i - 1) % 4 == 0)
        {
            swap_elements(array+i, array+i+1);
        }

        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    invers_thirds_and_print(array, ARRAY_SIZE);
    return 0;
}