//Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа. Число не превосходит 100.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);
    if (number <= 100 && number > 0)
    {
        for (int32_t i = 1; i <= number; i++)
        {
            printf("%d %d %d\n", i, i*i, i*i*i);
        }
    }
    else
    {
        printf("Wrong input.\n");
    }
    return 0;
}