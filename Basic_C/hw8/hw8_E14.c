//Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более одного раза.
//В результирующем массиве эти числа не должны повторяться.

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

void sort_up(int array[], int arr_size)
{
    for (int i = 0; i < arr_size - 1; i++)
    {
        for(int j = 1; j < arr_size - i; j++)
        {
            if (array[j] < array[j - 1] )
            {
                swap_elements(array+j, array+j-1);
            }
        }
    }
}

int pick_duplicates(int input_array[], int arr_size, int result_array[])
{
    int duplicates_counter = 0;
    sort_up(input_array, arr_size);
    int counter = 1;
    int j = 0;
    int current_number = input_array[0];
    for (int i = 1; i < arr_size; i++)
    {
        if (input_array[i] == current_number)
        {
            counter++;
        }
        if (input_array[i] != current_number || i == arr_size - 1)
        {
            if (counter > 1)
            {
                result_array[j] = current_number;
                duplicates_counter++;
                j++;
            }
            current_number = input_array[i];
            counter = 1;
        }
    }
    return duplicates_counter;
}

int main(void)
{
    int array[ARRAY_SIZE], results[ARRAY_SIZE], duplicates_counter;
    fill_array(array, ARRAY_SIZE);
    duplicates_counter = pick_duplicates(array, ARRAY_SIZE, results);
    print_array(results, duplicates_counter);
    printf("\n");
    return 0;
}