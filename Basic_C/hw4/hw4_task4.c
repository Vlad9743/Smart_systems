//Напечатать сумму максимума и минимума.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t n[5];
    scanf("%hd%hd%hd%hd%hd", &n[0], &n[1], &n[2], &n[3], &n[4]);
    int16_t max = n[0], min = n[0];

    for (int i = 0; i < 5; i++)
    {
        if (n[i] > max) max = n[i];
        if (n[i] < min) min = n[i];
    }

    printf("%hd\n", max+min);
}