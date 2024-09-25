//Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования.

#include <stdio.h>
#include <inttypes.h>

int nod(int number_a, int number_b)
{
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
    return(number_a + number_b);
}

int main(void)
{
    int number_a, number_b;
    scanf("%d%d", &number_a, &number_b);

    printf("%d\n", nod(number_a, number_b));
    return 0;
}