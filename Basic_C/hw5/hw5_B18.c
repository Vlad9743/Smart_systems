//Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.

#include <stdio.h>
#include <inttypes.h>
 
int main(void)
{
    int32_t number, a = 1, b = 1, temp;
    scanf("%d", &number);

    if (number == 1)
    {
        printf("%d\n", a);
    }
    
    else if (number == 2)
    {
        printf("%d %d\n", a, b);
    }

    else
    {
        printf("%d %d ", a, b);

        for (int i = 0; i < number - 2; i++)
        {
            printf("%d ", a + b);
            temp = b;
            b = a + b;
            a = temp;
        }
        printf("\n");
    }

    return 0;
}
