//Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. Составить рекурсивную функцию.

#include <stdio.h>

unsigned long long decimal_to_binary(int number)
{
    if (number > 0)
    {           
        return (number % 2) + 10 * decimal_to_binary(number / 2);
    }
    return 0;
}
 

int sum_digits(unsigned long long n)
{
    if (n > 0)
    {           
        return n % 10 + sum_digits(n / 10);
    }
    return 0;
}

int main(void)
{
    int number;
    unsigned long long binary;
    scanf("%d", &number);
    binary = decimal_to_binary(number);
    //printf("%llu\n", binary);
    printf("%d\n", sum_digits(binary));
    return 0;
}