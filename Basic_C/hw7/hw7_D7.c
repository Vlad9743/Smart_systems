//Составить рекурсивную функцию, печать всех чисел от N до 1.

#include <stdio.h>

void print_n_backward(int number)
{
    if (number > 0)
    {   
        printf("%d ", number);
        print_n_backward(number - 1);
    }
}
 
int main(void)
{
    int number;
    scanf("%d", &number);
    print_n_backward(number);
    printf("\n");
    return 0;
}