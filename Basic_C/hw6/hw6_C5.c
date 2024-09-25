//Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.

#include <stdio.h>
#include <inttypes.h>

int sum_one_to_n(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
 
int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%d\n", sum_one_to_n(n));
    return 0;
}