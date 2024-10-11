//Дан целочисленный массив из 30 элементов.
//Элементы массива могут принимать произвольные целые значения помещающиеся в int.
//Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна.

#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE 30

void read_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

int find_min_number(int size, int a[])
{
    int min = INT_MAX;
    int min_index = 0;
    for (int i = 0; i < size; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            min_index = i;
        }
    }
    return min_index;
}

int find_min_number_except(int size, int a[], int exception_index)
{
    int min = INT_MAX;
    int min_index = 0;
    for (int i = 0; i < size; i++)
    {
        if (min > a[i] && i != exception_index)
        {
            min = a[i];
            min_index = i;
        }
    }
    return min_index;
}

int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);

    int first_min_index = find_min_number(ARRAY_SIZE, array);
    int second_min_index = find_min_number_except(ARRAY_SIZE, array, first_min_index);

    if (first_min_index > second_min_index)
    {
        printf("%d %d\n", second_min_index, first_min_index);
    }
    else
    {
        printf("%d %d\n", first_min_index, second_min_index);
    }

    return 0;
}