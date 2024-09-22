//Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);

    int flag = 0;
    if (number > 10)
    {
        int32_t last_digit = number % 10;
        while (number > 0)
        {
            number /= 10;
            if (last_digit == number % 10)
            {
                flag = 1;
                break;
            }
            else
            {
                last_digit = number % 10;
            }
        }
        
        switch (flag)
        {
        case 0:
            printf("NO\n");
            break;
    
        case 1:
            printf("YES\n");
            break;
        }
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}