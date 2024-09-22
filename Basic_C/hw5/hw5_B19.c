//Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);

    int32_t sum = 0;

    while (number > 0)
    {
        sum += (number % 10); 
        number /= 10;
    }

    if (sum == 10)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}