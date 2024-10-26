//В файле input.txt дано предложение требуется разобрать его на отдельные слова.
// Напечатать каждое слово на отдельной строке в файл output.txt.

#include <stdio.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    
    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {
            char word[100] = "";
            while (fscanf(input, "%s", word) != EOF)
            {
                fprintf(output, word, "%s");
                fputc('\n', output);
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