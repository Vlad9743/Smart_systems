//Написать функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные.
// Не нарушайте порядок следования чисел между собой

#include <stdio.h>

#define ARRAY_SIZE 20

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

void sort_even_odd(int n, int a[])
{
    int temp_array[n];
    int even_index = 0, odd_index = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            temp_array[even_index] = a[i];
            even_index++;
        }
        if (a[n - 1 - i] % 2 != 0)
        {
            temp_array[odd_index] = a[n - 1 - i];
            odd_index--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = temp_array[i];
    }
}

int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);
    sort_even_odd(ARRAY_SIZE, array);
    print_array(ARRAY_SIZE, array);
    printf("\n");

    return 0;
}

