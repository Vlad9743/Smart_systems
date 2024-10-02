//Составить рекурсивную функцию, печать всех простых множителей числа.

#include <stdio.h>

void print_simple(int n)
{   
    if (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                printf("%d ", i);
                print_simple(n/i);
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