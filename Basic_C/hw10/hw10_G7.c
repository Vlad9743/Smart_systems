//В файле input.txt считать символьную строку, не более 10 000 символов. 
//Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. 
//Учитывать только английские буквы. Результат записать в файл output.txt.

#include <stdio.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char letter;

    int little_counter = 0;
    int capital_counter = 0;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {
            while ((letter = fgetc(input)) != EOF)
            {
                if (letter >= 'a' && letter <= 'z')
                {
                    little_counter++;
                }
                else if (letter >= 'A' && letter <= 'Z')
                {
                    capital_counter++;
                }
            }

            fprintf(output, "%d ", little_counter);
            fprintf(output, "%d", capital_counter);

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