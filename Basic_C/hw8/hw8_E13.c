//Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.

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

int pick_0x_numbers(int input_array[], int arr_size, int result_array[])
{   
    int counter = 0;
    int j = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if ((input_array[i] / 10) % 10 == 0)
        {
            result_array[j] = input_array[i];
            j++;
            counter++;
        }
    }
    return counter;
}

int main(void)
{
    int array[ARRAY_SIZE], results[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    int counter = pick_0x_numbers(array, ARRAY_SIZE, results);
    print_array(results, counter);
    printf("\n");
    return 0;
}