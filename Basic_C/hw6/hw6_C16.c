//Составить функцию логическую функцию, которая определяет, верно ли, что число простое. Используя функцию решить задачу.

#include <stdio.h>
#include <inttypes.h>

int is_prime(int n)
{
    int dividers = 2;
    for (int i = 2; i < n; i++)
    {   
        if (n % i == 0)
        {
            dividers++;
            break;
        }
    }
    return dividers;
}

int main(void)
{
    int number;
    scanf("%d", &number);

    int prime = is_prime(number);

    if (number == 1 || number == 0)
    {
        printf("NO\n");
    }
    else if (prime == 2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}