//Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
//Прототип функции void change_max_min(int size, int a[])

#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE 10

void read_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

void print_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

void change_max_min(int size, int a[])
{
    int max = INT_MIN;
    int min = INT_MAX;
    int max_index = 0;
    int min_index = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            max_index = i;
        }
        if (a[i] < min)
        {
            min = a[i];
            min_index = i;
        }
    }
    int temp;
    temp = a[min_index];
    a[min_index] = a[max_index];
    a[max_index] = temp;
}

int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);
    change_max_min(ARRAY_SIZE, array);
    print_array(ARRAY_SIZE, array);
    printf("\n");

    return 0;
}