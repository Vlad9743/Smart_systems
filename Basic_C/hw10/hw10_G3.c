//В файле input.txt дана строка из 1000 символов.
// Показать номера символов, совпадающих с последним символом строки. Результат записать в файл output.txt

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char last_symbol;
    int last_pos;
    char current_symbol;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {
            fseek(input, -1, SEEK_END);
            last_symbol = fgetc(input);
            last_pos = ftell(input);

            fseek(input, 0, SEEK_SET);
            
            current_symbol = fgetc(input);
            int i = 1;

            while (i < last_pos - 1)
            {
                if (current_symbol == last_symbol)
                {                       
                    fprintf(output, "%d ", i);
                }   
                current_symbol = fgetc(input);
                i++;
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