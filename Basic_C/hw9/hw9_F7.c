//Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей по следующему принципу:
// например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4] (т.к. начинается с нуля, 
//то сразу записывается количество элементов первой серии); 
//а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7] (т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).

#include <stdio.h>

#define ARRAY_SIZE 100

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

int compression(int a[], int b[], int N)
{
    int current_sum = 0;
    int b_index = 0;

    if (a[0] == 1)
    {
        b[0] = 0;
        b_index++;
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            current_sum++;
        }
        else
        {
            b[b_index] = current_sum + 1;
            b_index++;
            current_sum = 0;
        }
    }
    b[b_index] = current_sum + 1;
    return b_index + 1;
}

int main(void)
{
    int original_array[ARRAY_SIZE];
    int compressed_array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, original_array);

    int compressed_size = compression(original_array, compressed_array, ARRAY_SIZE);

    for (int i = 0; i < compressed_size; i++)
    {
        printf("%d, ", compressed_array[i]);
    }
    printf("\n");

    return 0;
}