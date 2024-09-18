//Ввести два числа. Если первое число больше второго, то программа печатает слово Above. 
//Если первое число меньше второго, то программа печатает слово Less. 
//А если числа равны, программа напечатает сообщение Equal.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t n1, n2;
    scanf("%hd%hd", &n1, &n2);
    if (n1 > n2) printf("Above\n");
    else if (n1 < n2) printf("Less\n");
    else printf("Equal\n");
    return 0;
}