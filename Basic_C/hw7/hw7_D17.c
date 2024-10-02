//Реализовать функцию Аккермана по прототипу
//int akkerman(int m, int n)

#include <stdio.h>

int akkerman(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return akkerman(m - 1, 1);
    }
    else if (m > 0 && n > 0)
    {
        return akkerman(m - 1, akkerman(m, n - 1));
    }
}

int main(void)
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", akkerman(m, n));
    return 0;
}