//Ввести целое число и найти сумму его цифр.
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);

    int32_t sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    printf("%d\n", sum);
    return 0;
}