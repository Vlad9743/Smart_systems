//Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, НЕ обязательно стоящие рядом.
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);

    int32_t temp, flag = 0, current_number;
    while (number > 0 && flag == 0)
    {
        current_number = number % 10;
        temp = number / 10;
        while (temp > 0 && flag == 0)
        {
            if (current_number == temp % 10)
            {
                flag = 1;
            }
            else
            {
                temp /= 10;
            }
        }
        number /= 10;
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

    return 0;
}