//Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.

#include <stdio.h>

int is2pow(int n)
{
    if (n % 2 != 0)
    {
        if (n == 1)
        {
            return 0;
        }
        return 1;
    }
    return is2pow(n / 2);
}

int main(void)
{
    int number, flag;
    scanf("%d", &number);
    flag = is2pow(number);

    if (flag == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}