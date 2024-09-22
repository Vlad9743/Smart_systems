//Ввести натурально число и напечатать все числа от 10 до введенного числа - у которых сумма цифр равна произведению цифр

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);

    for (int32_t i = 10; i <= number; i++)
    {
        int32_t current_number = i;
        int32_t sum = 0;
        int32_t mult = 1;
        while (current_number > 0)
        {
            sum += (current_number % 10);
            mult *= (current_number % 10);
            current_number /= 10; 
        }

        if (sum == mult)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    return 0;
}