//Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел,
//сколько элементов превосходят по модулю максимальный элемент.
//Прототип функции int count_bigger_abs(int n, int a[]);

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void read_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

int count_bigger_abs(int n, int a[])
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }

    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) > max)
        {
            counter++;
        }
    }
    return counter;
}


int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);

    int quantity_bigger_abs =  count_bigger_abs(ARRAY_SIZE, array);
    printf("%d\n", quantity_bigger_abs);

    return 0;
}