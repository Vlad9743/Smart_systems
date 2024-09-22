//Ввести целое число и определить, верно ли, что все его цифры четные.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);

    int32_t no_odds = 1;
    while (number > 0 && no_odds == 1)
    {
        if ((number % 10) % 2 != 0)
        {
            no_odds = 0;
        }
        number /= 10;
    }

    if (no_odds == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}