//Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t original_number, backward_number;
    scanf("%d", &original_number);

    while (original_number > 0)
    {
        backward_number += original_number % 10;
        backward_number *= 10;
        original_number /= 10;
    }

    backward_number /= 10;
    printf("%d\n", backward_number);
    
    return 0;
}