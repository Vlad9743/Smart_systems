//Посчитать количество четных и нечетных цифр числа.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number, odds_quantity = 0, evens_quantity = 0, temp;
    scanf("%d", &number);

    while (number > 0)
    {
        temp = number % 10;
        if (temp % 2 == 0)
        {
            evens_quantity++;
        }
        else
        {
            odds_quantity++;
        }
        number /= 10;
    }

    printf("%d %d\n", evens_quantity, odds_quantity);
    
    return 0;
}