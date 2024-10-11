//Сортировка массива по возрастанию

#include <stdio.h>

#define ARRAY_SIZE 20

void sort_array(int size, int a[])
{
    int temp;
    for (int i = 0; i < size - 1 ; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (a[j] < a[j - 1])
            {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }   
}

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

int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);
    sort_array(ARRAY_SIZE, array);
    print_array(ARRAY_SIZE, array);
    printf("\n");

    return 0;
}