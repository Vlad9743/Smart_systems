//Дана строка из английских символов, пробелов и знаков препинания.
// В конце строки символ точка.
// Необходимо реализовать рекурсивную функцию, которая считывает данную строку со стандартного потока ввода и
// возвращает целое число - количество символов 'a' в данной строке.
//int acounter(void)
//Используя данную функцию решить задачу.

#include <stdio.h>

int acounter(void)
{
    char letter;
    int static counter = 0;
    scanf("%c", &letter);
    if (letter != '.')
    {
        if (letter == 'a')
        {
            counter++;
        }
        acounter();
    }
    return counter;
}

int main(void)
{
    int number_of_a = acounter();
    printf("%d\n", number_of_a);
    return 0;
}