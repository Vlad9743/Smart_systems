//Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);

    int32_t quontity_of_9 = 0;
    while (number > 0 && quontity_of_9 <= 1)
    {
        if (number % 10 == 9)
        {
            quontity_of_9++;
        }
        number /= 10;
    }

    if (quontity_of_9 == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}