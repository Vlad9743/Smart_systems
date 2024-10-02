//Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N

#include <stdio.h>

int sum_n(int number)
{
    if (number > 0)
    {           
        return number + sum_n(number - 1);
    }
    return 0;
}
 
int main(void)
{
    int number, sum = 0;
    scanf("%d", &number);
    sum = sum_n(number);
    printf("%d\n", sum);
    return 0;
}