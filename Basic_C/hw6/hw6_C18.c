//Составить логическую функцию, которая определяет, что текущий символ это цифра. Написать программу считающую количество цифр в тексте.
//Текст из английских букв и знаков препинания. В конце текста символ точка.

#include <stdio.h>

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int counter = 0;
    char c;
    do
    {
        scanf("%c", &c);
        counter += is_digit(c);
    } while (c != '.');
    
    printf("%d\n", counter);
}