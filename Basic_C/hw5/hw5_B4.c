//Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t number;
    scanf("%d", &number);
    if (number > 99 && number < 999)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}