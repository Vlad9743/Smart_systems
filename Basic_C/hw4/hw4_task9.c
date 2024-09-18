//Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t n1, n2, n3;
    scanf("%hd%hd%hd", &n1, &n2, &n3);

    if (n1 < n2 && n2 < n3) printf("YES\n");
    else printf("NO\n");
}