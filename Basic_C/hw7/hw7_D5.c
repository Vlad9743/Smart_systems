//Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.

#include <stdio.h>

unsigned long long decimal_to_binary(int number)
{
    if (number > 0)
    {           
        return (number % 2) + 10 * decimal_to_binary(number / 2);
    }
    return 0;
}
 
int main(void)
{
    int number;
    unsigned long long binary;
    scanf("%d", &number);
    binary = decimal_to_binary(number);
    printf("%llu\n", binary);
    return 0;
}