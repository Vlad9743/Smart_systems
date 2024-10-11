//Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
// Прототип функции int sum_between_ab(int from, int to, int size, int a[])

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

int sum_between_ab(int from, int to, int size, int a[])
{
    if (to < from)
    {
        int temp = from;
        from = to;
        to = temp;
    }
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] <= to && a[i] >= from)
        {
            sum += a[i];
        }
    }
    return sum;
}


int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);

    int start = 60, end = 50;
    int sum_between =  sum_between_ab(start, end, ARRAY_SIZE, array);
    printf("%d\n", sum_between);

    return 0;
}