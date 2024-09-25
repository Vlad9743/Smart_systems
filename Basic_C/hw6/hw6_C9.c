//Составить функцию вычисления N!. Использовать ее при вычислении факториала

#include <stdio.h>
#include <inttypes.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        int result = 1;
        for (int i = 1; i <= n; i++)
        {
            result *= i;
        }
        return result;
    }
}
 
int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%d\n", factorial(n));
    return 0;
}