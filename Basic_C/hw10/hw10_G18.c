//В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы).
// Для решения задачи разработать функцию. Результат записать в output.txt.

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char buffer[10000];
    char *ptr;
    char letter;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {   
            while ((letter = getc(input)) == ' ')
            {
              //skip to first symbol   
            }
            fputc(letter, output);
            
            while ((letter = getc(input)) != EOF)
            {
                fputc(letter, output);
                if (letter == ' ')
                {
                    while ((letter = getc(input)) == ' ')
                    {
        
                    }
                    fputc(letter, output);
                }
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