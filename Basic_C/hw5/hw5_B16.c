// Составить программу для вычисления НОД с помощью алгоритма Евклида. Даны два натуральных числа. Найти наибольший общий делитель.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number_a, number_b;
    scanf("%d %d", &number_a, &number_b);


    while (number_a != 0 && number_b != 0)
    {
        if (number_a > number_b)
        {
            number_a = number_a % number_b;
        }
        else
        {
            number_b = number_b % number_a;
        }
    }

    printf("%d\n", number_a + number_b);
    
    return 0;
}