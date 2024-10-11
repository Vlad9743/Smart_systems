//Найти максимум в массиве

#include <stdio.h>

#define ARRAY_SIZE 99

void read_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

int find_max_array(int size, int a[])
{
    int max = a[0];
    for (int i = 0; i < size; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);

    int max = find_max_array(ARRAY_SIZE, array);
    printf("%d\n", max);

    return 0;
}