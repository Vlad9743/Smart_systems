//Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот.
//Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.

#include <stdio.h>

void print_backward(void)
{
    char letter;
    scanf("%c", &letter);
    if (letter != '.')
    {           
        print_backward();
        printf("%c", letter);
    }
}
 
int main(void)
{
    print_backward();
    printf("\n");
    return 0;
}