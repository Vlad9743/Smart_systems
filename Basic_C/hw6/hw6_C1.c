//Составить функцию, модуль числа и привести пример ее использования.

#include <stdio.h>
#include <inttypes.h>

int32_t abs_value(int32_t number)
{
    if (number >= 0) 
    {
        return number;
    }
    else
    {
        return -1*number;
    }
}
 
int main(void)
{
    int32_t number;
    scanf("%d", &number);

    printf("%d\n", abs_value(number));
    return 0;
}