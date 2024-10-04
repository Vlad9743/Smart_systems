//Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.

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

void sort_up_in_area(int array[], int arr_size, int start_index, int end_index)
{
    for (int i = 0; i < end_index - start_index; i++)
    {
        for(int j = start_index + 1; j <= end_index - i; j++)
        {
            if (array[j] < array[j - 1])
            {
                swap_elements(array+j, array+j-1);
            }
        }
    }
}

void sort_down_in_area(int array[], int arr_size, int start_index, int end_index)
{
    for (int i = 0; i < end_index - start_index; i++)
    {
        for(int j = start_index + 1; j <= end_index - i; j++)
        {
            if (array[j] > array[j - 1])
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
    sort_up_in_area(array, ARRAY_SIZE, 0, ARRAY_SIZE/2 - 1);
    sort_down_in_area(array, ARRAY_SIZE, ARRAY_SIZE/2, ARRAY_SIZE - 1);
    print_array(array, ARRAY_SIZE);
    printf("\n");
    return 0;
}