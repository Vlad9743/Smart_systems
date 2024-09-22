//Проверить число на простоту.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number, dividers = 2;
    scanf("%d", &number);

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            dividers++;
            break;
        }
    }
    
    if (number == 1)
    {
        printf("NO\n");
    }
    else if (dividers == 2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}