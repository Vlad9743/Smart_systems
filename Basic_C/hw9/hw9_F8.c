//В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке,
// но одно из чисел пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000. 
//Последовательность заканчивается числом 0. Определить пропущенное число.

#include <stdio.h>

#define MAX_LENGTH 1000

int read_array(int a[])
{
    int number;
    int length = 0;
    while (1)
    {
        scanf("%d", &number);
        if (number == 0)
        {
            break;
        }
        a[length] = number;
        length++;
    }
    
    return length;
}

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

int find_gap(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] != a[i+1] - 1)
        {
            return a[i] + 1;
        }
    }
    return -1;
}

int main(void)
{
    int array[MAX_LENGTH];
    int true_length;

    true_length = read_array(array);
    sort_array(true_length, array);
    printf("%d\n", find_gap(true_length, array));

    return 0;
}