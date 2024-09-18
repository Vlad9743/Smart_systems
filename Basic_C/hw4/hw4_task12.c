#include <stdio.h>

int main(void)
{
    int a, result = 0;
    scanf("%d", &a);

    for (int i = 0; i < 3; i++)
    {
        result += a % 10;
        a /= 10;   
    }

    printf("%d\n", result); 
    return 0;
}