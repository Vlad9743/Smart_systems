//Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t a, b;
    scanf("%d%d", &a, &b);
    if (a <= b)
    {
        for (int32_t i = a; i <= b; i++)
        {
            printf("%d ", i*i);
        }
        printf("\n");
    }
    else
    {
        printf("Wrong input.\n");
    }
    return 0;
}