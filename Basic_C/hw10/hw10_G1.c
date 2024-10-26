//В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char letter;
    char buffer[100] = "";

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {
            int pos = 0;
            while ((letter = fgetc(input)) != EOF)
            {
                buffer[pos] = letter;
                pos++;
            }

            int length = strlen(buffer);
            for (int i = 0; i < 3; i++)
            {
                int j = 0;
                while (j < length - 1)
                {
                    fputc(buffer[j], output);
                    j++;
                }
                
                fputs(", ", output);
            }
            
            fseek(output, -2, SEEK_END);
            fprintf(output, " %d", pos - 1);

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