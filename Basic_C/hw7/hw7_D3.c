//Дано целое не отрицательное число N. 
//Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками. Составить рекурсивную функцию.

#include <stdio.h>

void print_digits(int number)
{
    if (number > 0)
    {        
        printf("%d ", number % 10);   
        print_digits(number/10);
    }
}
 
int main(void)
{
    int number;
    scanf("%d", &number);
    if (number == 0)
    {
        printf("%d", number);
    }
    else
    {
        print_digits(number);
    }
    printf("\n");
    return 0;
}