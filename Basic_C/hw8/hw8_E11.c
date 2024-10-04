//Считать массив из 10 элементов и отсортировать его по последней цифре.

#include <stdio.h>

#define ARRAY_SIZE 10

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void print_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", array[i]);
    }
}

void swap_elements(int *elem1, int *elem2)
{
    int temp;
    temp = *elem2;
    *elem2 = *elem1;
    *elem1 = temp;
}

void sort_by_last_digit(int array[], int arr_size)
{
    for (int i = 0; i < arr_size - 1; i++)
    {
        for(int j = 1; j < arr_size - i; j++)
        {
            if ((array[j] % 10) < (array[j - 1] % 10))
            {
                swap_elements(array+j, array+j-1);
            }
        }
    }
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    sort_by_last_digit(array, ARRAY_SIZE);
    print_array(array, ARRAY_SIZE);
    printf("\n");
    return 0;
}