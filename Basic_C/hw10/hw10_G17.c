//В файле input.txt записаны символы. Необходимо разработать функцию, которая меняет местами пары
// соседних символов не обращая внимание на символы пробел. 
//Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. Результат записать в файл output.txt.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char buffer[100];
    char letter;


    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {   
            int symbols_number = 0; // count number of non space symbols
            while ((letter = fgetc(input)) != EOF)
            {
                if (letter != ' ')
                {
                    symbols_number++;
                }
            }
            fseek(input, 0, SEEK_SET);
            

            int i = 0;
            while (fscanf(input, "%[^\n]s", buffer) != EOF)
            {
                int length = strlen(buffer);
                
                while (i < length - 1)
                {
                    int j = i + 1;
                    while (buffer[j] == ' ')
                    {
                        j++;
                    }

                    fputc(buffer[j], output);
                    for(int k = 1; k < j - i; k++)
                    {
                        fputc(' ', output);
                    }
                    fputc(buffer[i], output);

                    i = j + 1;
                }
            }

            //last symbol
            int j = -1;
            if (symbols_number % 2 != 0)
            {
                fseek(input, j, SEEK_END);
                while ((letter = fgetc(input)) == ' ')
                {
                    j--;
                    fseek(input, j, SEEK_END);
                }
                fputc(letter, output);
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