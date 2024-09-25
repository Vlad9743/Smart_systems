//Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.

#include <stdio.h>
#include <inttypes.h>

int translate(int n, int p)
{
    int result = 0, place = 1;
    while (n > 0)
    {
        result += (n % p) * place;
        place *= 10;
        n /= p;
    }
    return result;
}
 
int main(void)
{
    int n, p;
    scanf("%d%d", &n, &p);

    printf("%d\n", translate(n, p));
    return 0;
}