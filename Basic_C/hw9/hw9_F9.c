//Составить только функцию которая в массиве находит максимальный из отрицательных элементов и 
//меняет его местами с последним элементом массива.
//Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует.
//Если отрицательных элементов нет - массив не менять.

#include <stdio.h>

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

void swap_negmax_last(int size, int a[])
{
    int negmax;
    int negmax_index = -1;

    for (int i = 0; i < size; i++)//find first negative
    {
        if (a[i] < 0)
        {
            negmax = a[i];
            negmax_index = i;
            break;
        }
    }

    if (negmax_index == -1)//exit if no negatives
    {
        return;
    }

    for (int i = negmax_index; i < size; i++)
    {
        if (a[i] < 0 && negmax < a[i])
        {
            negmax = a[i];
            negmax_index = i;
        }
    }

    int temp;
    temp = a[size - 1];
    a[size - 1] = a[negmax_index];
    a[negmax_index] = temp;
}

int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);
    swap_negmax_last(ARRAY_SIZE, array);
    print_array(ARRAY_SIZE, array);
    printf("\n");

    return 0;
}