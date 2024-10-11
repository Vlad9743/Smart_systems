//Написать функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых.
// Если ответ «да», функция возвращает 1; если ответ «нет», то 0

#include <stdio.h>

#define ARRAY_SIZE 100

void read_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

int is_two_same(int size, int a[])
{
    int flag_two_same = 0;

    int i = 0, j;
    while (flag_two_same == 0 && i < size)
    {
        j = i + 1;
        while (flag_two_same == 0 && j < size)
        {
            if (a[i] == a[j])
            {
                flag_two_same = 1;
            }
            j++;
        }
        i++;
    }
    
    return flag_two_same;
}

int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);

    int flag = is_two_same(ARRAY_SIZE, array);
    printf("%d\n", flag);

    return 0;
}