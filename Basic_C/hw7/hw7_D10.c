//Дано натуральное число n ≥ 1. Проверьте, является ли оно простым.
//Программа должна вывести слово YES, если число простое или NO в противном случае.
// Необходимо составить рекурсивную функцию и использовать ее.

#include <stdio.h>

int is_prime(int n, int delitel)
{
    int number_of_dividers = 0;

    if (delitel <= n)
    {
        if (n % delitel == 0)
        {
            number_of_dividers++;
        }
        return number_of_dividers + is_prime(n, ++delitel);
    }
    return 0;
}

int main(void)
{
    int number, number_of_dividers;
    scanf("%d", &number);

    if (number == 0 || number == 1)
    {
        printf("NO\n");
    }
    else
    {
        number_of_dividers = is_prime(number, 1);
        if (number_of_dividers <= 2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}