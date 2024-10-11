//Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр.
//Цифра, пробел, сколько раз данная цифра встречается в числе.

#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 1000

void read_string(char st[])
{
    char letter;
    int i = 0;
    
    while ((letter = getchar()) != '\n' && i < ARRAY_SIZE)
    {
        st[i] = letter;
        i++;
    }
}

void count_digits(int length, char number[], int digits_array[])
{
    int i = 0;
    while (number[i] != 0)
    {
        digits_array[number[i] - '0']++;
        i++;
    }
}

void print_digits_array(int digits_array[])
{
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
    char number[ARRAY_SIZE];
    read_string(number);
    int length = strlen(number);

    int digits_array[10] = {0};
    count_digits(length, number, digits_array);
    print_digits_array(digits_array);

    return 0;
}