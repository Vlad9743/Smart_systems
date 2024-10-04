//Переставить цифры в числе так, что бы получилось максимальное число.

#include <stdio.h>

int count_digits(int number)
{   
    int counter = 0;
    while (number > 0)
    {
        number /= 10;
        counter++;
    }
    return counter;
}

void number_to_array(int number, int array[], int arr_size)
{
    for (int i = arr_size - 1; i >= 0; i--)
    {
        array[i] = number % 10;
        number /= 10;
    }
}

void swap_elements(int *elem1, int *elem2)
{
    int temp;
    temp = *elem2;
    *elem2 = *elem1;
    *elem1 = temp;
}

void sort_down(int array[], int arr_size)
{
    for (int i = 0; i < arr_size - 1; i++)
    {
        for(int j = 1; j < arr_size - i; j++)
        {
            if (array[j] > array[j - 1] )
            {
                swap_elements(array+j, array+j-1);
            }
        }
    }
}

int array_to_number(int array[], int arr_size)
{
    int number = 0;
    for (int i = 0; i < arr_size; i++)
    {
        number += array[i];
        number *= 10;
    }
    number /= 10;
    return number;
}

int main(void)
{
    int number;
    scanf("%d", &number);
    int number_length = count_digits(number);
    int array[number_length];
    number_to_array(number ,array, number_length);
    sort_down(array, number_length);
    number = array_to_number(array, number_length);
    printf("%d\n", number);
    return 0;
}