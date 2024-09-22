//Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);

    int32_t rising_order = 1, current_digit;
    while (number > 0 && rising_order == 1)
    {
        current_digit = number % 10;
        number /= 10;

        if (current_digit <= number % 10)
        {
            rising_order = 0;
        }
    }

    if (rising_order == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}