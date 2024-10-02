//Составить рекурсивную функцию, печать всех чисел от 1 до N

#include <stdio.h>

void print_n(int number)
{
    if (number > 0)
    {   
        print_n(number - 1);
        printf("%d ", number);
    }
}
 
int main(void)
{
    int number;
    scanf("%d", &number);
    print_n(number);
    printf("\n");
    return 0;
}