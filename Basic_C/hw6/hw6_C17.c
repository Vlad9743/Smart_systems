//Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению.

#include <stdio.h>
#include <inttypes.h>

int is_happy_number(int n)
{
    int sum = 0;
    int mult = 1;

    while (n > 0)
    {
        sum += (n % 10);
        mult *= (n % 10);
        n /= 10; 
    }
    return sum - mult;
}

int main(void)
{
    int number;
    scanf("%d", &number);

    int happy = is_happy_number(number);

    if (happy != 0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}