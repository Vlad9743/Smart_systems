//Организовать ввод натурального числа с клавиатуры. 
//Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);

    int32_t min_digit = number % 10, max_digit = number % 10, temp;

    while (number > 0)
    {
        
        temp = number % 10;
        if (min_digit > temp)
        {
            min_digit = temp;
        }
        else if (max_digit < temp)
        {
            max_digit = temp;
        }
        number /= 10;
    }

    printf("%d %d\n", min_digit, max_digit);
    
    return 0;
}