//Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.

#include <stdio.h>

int sum_digits(int n)
{
    if (n > 0)
    {           
        return n % 10 + sum_digits(n / 10);
    }
    return 0;
}
 
int main(void)
{
    int number, sum = 0;
    scanf("%d", &number);
    sum = sum_digits(number);
    printf("%d\n", sum);
    return 0;
}