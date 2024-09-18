//Ввести три числа и найти наибольшее из них

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t a = 0, b = 0, c = 0;
    scanf("%hd%hd%hd", &a, &b, &c);

    int16_t max = a;

    if (b > max) max = b;
    if (c > max) max = c;

    printf("%hd\n", max);
}