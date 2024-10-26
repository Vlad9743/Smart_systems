//В файле input.txt символьная строка не более 1000 символов.
// Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях).
// Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.

#include <stdio.h>
#include <string.h>

int is_palindrom(char str[])
{
    int polindrom_positive = 1;
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++)
    {   
        if (str[i] != str[length - 1 - i])
        {
            polindrom_positive = 0;
            break;
        }
    }
    

    return polindrom_positive;
}

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char input_string[1000] = "";

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {
            fscanf(input, "%s", input_string);
            int poli_flag = is_palindrom(input_string);

            if (poli_flag == 1)
            {
                fprintf(output, "YES");
            }
            else
            {
                fprintf(output, "NO");
            }

            fclose(output);
        }
        else
        {
            printf("Can't open output file.\n");
        }

        fclose(input);
    }
    else 
    {
        printf("Can't open input file.\n");
    }

}