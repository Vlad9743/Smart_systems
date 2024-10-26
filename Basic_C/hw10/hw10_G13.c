//В файле input.txt записан полный адрес файла (возможно, без расширения).
// Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char input_string[1000] = "";
    char output_string[1000] = "";

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {   
            fscanf(input, "%s", input_string);
            int pos = strlen(input_string) - 1;

            for (pos; pos >= 0; pos--)
            {
                if (input_string[pos] == '.')
                {
                    strncpy(output_string, input_string, pos);
                    strcat(output_string, ".html");
                    break;
                }
                else if (input_string[pos] == '/')
                {
                    strcpy(output_string, input_string);
                    strcat(output_string, ".html");
                    break;
                }
            }

            fprintf(output, "%s", output_string);

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