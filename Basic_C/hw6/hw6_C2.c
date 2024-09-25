//Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.

#include <stdio.h>
#include <inttypes.h>

int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    else
    {
        int result = 1;
        for (int i = 0; i < p; i++)
        {
            result *= n;
        }
        return result;
    }
}
 
int main(void)
{
    int n, p;
    scanf("%d%d", &n, &p);

    printf("%d\n", power(n, p));
    return 0;
}