//Дана последовательность целых чисел через пробел, завершающаяся числом 0. 
//Выведите все нечетные числа из этой последовательности, сохраняя их порядок.
//Составить рекурсивную функцию.

#include <stdio.h>

void print_odds(void)
{
    int digit;
    scanf("%d", &digit);
    if (digit != 0)
    {
        if (digit % 2 != 0)
        {
            printf("%d ", digit);
        }
        print_odds();
    }
}

int main(void)
{
    print_odds();
    printf("\n");
    return 0;
}