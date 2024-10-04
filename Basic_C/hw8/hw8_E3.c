//Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
//вывод: 4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.
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

void find_min_max_and_positions(int input_array[], int input_array_size, int results_array[4])
{
    int pos_max = 0,
        pos_min = 0,
        max = input_array[pos_max],
        min = input_array[pos_min];

    for (int i = 0; i < input_array_size; i++)
    {
        if (min > input_array[i])
        {
            min = input_array[i];
            pos_min = i;
        }
        if (max < input_array[i])
        {
            max = input_array[i];
            pos_max = i;
        }
    }

    results_array[0] = pos_max + 1;
    results_array[1] = max;
    results_array[2] = pos_min + 1;
    results_array[3] = min;
}

int main(void)
{
    int array[ARRAY_SIZE], results[4];
    fill_array(array, ARRAY_SIZE);
    find_min_max_and_positions(array, ARRAY_SIZE, results);
    print_array(results, 4);
    return 0;
}