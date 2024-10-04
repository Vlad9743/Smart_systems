//Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.

#include <stdio.h>

#define ARRAY_SIZE 12
#define STEP 4

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

void cicle_right(int array[], int arr_size, int step)
{
    int temp_array[arr_size];
    for (int i = 0; i < arr_size; i++)
    {
        temp_array[i] = array[i];
    }

    for (int i = 0; i < arr_size; i++)
    {
        if (i + step >= arr_size)
        {
            array[i + step - arr_size] = temp_array[i];
        }
        else
        {
            array[i + step] = temp_array[i];
        }
    }
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    cicle_right(array, ARRAY_SIZE, STEP);
    print_array(array, ARRAY_SIZE);
    printf("\n");
    return 0;
}