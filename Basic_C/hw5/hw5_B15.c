//Дана последовательность ненулевых целых чисел, в конце последовательности число 0. Посчитать количество четных чисел.

#include <stdio.h>
#include <inttypes.h>
 
int main(void)
{
    int32_t number, counter = 0;

    do
    {
        scanf("%d", &number);
        if (number != 0 && number % 2 == 0 )
        {
            counter ++;
        }
    } while (number != 0);

    printf("%d\n", counter);
    return 0;
}