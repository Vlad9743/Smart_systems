//Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t a, b;
    scanf("%d%d", &a, &b);
    if (a <= b)
    {
        int32_t sum = 0;

        for (int32_t i = a; i <= b; i++)
        {
            sum += i*i;
        }
        printf("%d\n", sum);
    }
    else
    {
        printf("Wrong input.\n");
    }
    return 0;
}