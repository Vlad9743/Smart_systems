//Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. 

#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 50

void read_string(char st[])
{
    char letter;
    int i = 0;
    
    while ((letter = getchar()) != '\n' && i < STRING_LENGTH)
    {
        st[i] = letter;
        i++;
    }
}

void print_digit(char s[])
{
    int digits_array[10] = {0};
    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            digits_array[s[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (digits_array[i] != 0)
        {
            printf("%d %d\n", i, digits_array[i]);
        }
    }
}

int main(void)
{
    char st[STRING_LENGTH] = "";
    read_string(st);

    print_digit(st);

    return 0;
}