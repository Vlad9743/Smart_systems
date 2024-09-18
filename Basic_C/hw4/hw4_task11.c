//Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t a, b, c;
    scanf("%hd%hd%hd", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a) printf("YES\n");
    else printf("NO\n");
}