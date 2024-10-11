//Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива.
// Прототип функции int count_between(int from, int to, int size, int a[])
// Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения

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

int count_between(int from, int to, int size, int a[])
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] <= to && a[i] >= from)
        {
            count++;
        }
    }
    return count;
}


int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);

    int start = 4, end = 7;
    int quantity_between =  count_between(start, end, ARRAY_SIZE, array);
    printf("%d\n", quantity_between);

    return 0;
}