//Написать рекурсивную функцию возведения целого числа n в степень p.
//int recurs_power(int n, int p)
//Используя данную функцию, решить задачу.
//-100 ≤ n ≤ 100 и 0 ≤ p ≤ 100

#include <stdio.h>

int recurs_power(int n, int p)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else if (p == 0)
    {
        return 1;
    }
    else if (p > 1)
    {
        return n * recurs_power(n, p - 1);
    }

}

int main(void)
{
    int n, p;
    scanf("%d%d", &n, &p);
    printf("%d\n", recurs_power(n, p));
}