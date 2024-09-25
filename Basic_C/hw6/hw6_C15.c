//Составить функцию логическую функцию, которая определяет, верно ли, 
//что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу.

#include <stdio.h>
#include <inttypes.h>

int grow_up(int n)
{
    int32_t rising_order = 1, current_digit;
    while (n > 0 && rising_order == 1)
    {
        current_digit = n % 10;
        n /= 10;

        if (current_digit <= n % 10)
        {
            rising_order = 0;
        }
    }

    return rising_order;
    
}

int main(void)
{
    int number;
    scanf("%d", &number);

    int order = grow_up(number);
    if (order == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}