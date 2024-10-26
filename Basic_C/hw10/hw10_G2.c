//Считать число N из файла input.txt. Сформировать строку из N символов.
// N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания,
// кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. Результат записать в файл output.txt

#include <stdio.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    int number;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {
            fscanf(input, "%d", &number);
            char symbol_string[number];
            
            char current_even_symbol = 'A';
            char current_odd_symbol = '2';

            int i = 0;
            while (i < number)
            {
                if (i % 2 == 0)
                {
                    symbol_string[i] = current_even_symbol;
                    current_even_symbol++;
                    if (current_even_symbol > 'Z')
                    {
                        current_even_symbol = 'A';
                    }
                }
                else
                {
                    symbol_string[i] = current_odd_symbol;
                    current_odd_symbol += 2;
                    if (current_odd_symbol > '9')
                    {
                        current_odd_symbol = '2';
                    }
                }
                i++;
            }

            int j = 0;
            while (j < number)
                {
                    fputc(symbol_string[j], output);
                    j++;
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

    return 0;
}