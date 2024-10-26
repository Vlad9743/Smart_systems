//В файле input.txt дана символьная строка не более 1000 символов. 
//Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.

#include <stdio.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char letter;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {   
            while ((letter = fgetc(input)) != EOF)
            {
                if (letter == 'a' || letter == 'A')
                {
                    fputc(letter + 1, output);
                }
                else if (letter == 'b' || letter == 'B')
                {
                    fputc(letter - 1, output);
                }
                else
                {
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