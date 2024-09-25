//Необходимо составить функцию, которая определяет, сколько зерен попросил положить на N-ую клетку изобретатель шахмат
// (на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)

#include <stdio.h>
#include <inttypes.h>

unsigned long long grains(int n)
{
    unsigned long long grains_num = 1;
    for (int i = 1; i < n; i++)
    {
        grains_num *= 2;
    }
    return grains_num;
}
 
int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%llu\n", grains(n));
    return 0;
}