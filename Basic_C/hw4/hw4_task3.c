//Дано трехзначное число, напечатать максимальную цифру

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t number, temp, max = 0;
    scanf("%hd", &number);
    for (int i = 0; i < 3; i++)
    {   
        temp = number%10;
        if (temp > max) max = temp;
        number /= 10; 
    }
    printf("%hd\n", max);
    return 0;
}