//Ввести два числа и вывести их в порядке возрастания.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t a = 0, b = 0;
    scanf("%hd%hd" SCNd16, &a, &b);
    if (a > b)
    {
        printf("%hd %hd\n", b, a);
    }
    else
    {
        printf("%hd %hd\n", a, b);
    }
    return 0;
}