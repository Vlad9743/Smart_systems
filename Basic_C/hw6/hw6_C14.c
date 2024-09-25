//Составить функцию логическую функцию, которая определяет, верно ли,
// что сумма его цифр – четное число. Используя эту функцию решить задачу.

#include <stdio.h>

void sum_is_even(int number)
{
    int sum = 0;

    while (number > 0)
    {
        sum += number % 10;
        number /= 10;    
    }
    
    if (sum % 2 == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

int main(void)
{
    int number;
    scanf("%d", &number);

    sum_is_even(number);
    return 0;
}