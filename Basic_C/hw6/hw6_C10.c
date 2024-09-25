//Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа.

#include <stdio.h>
#include <inttypes.h>

void print_simple(int n)
{
    int counter = 0;

    while(n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                printf("%d ", i);
                n /= i;
                counter++;
                break;
            }
        }
    }
}
 
int main(void)
{
    int n;
    scanf("%d", &n);

    print_simple(n);
    printf("\n");
    return 0;
}