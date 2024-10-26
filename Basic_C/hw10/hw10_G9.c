//В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
// Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.

#include <stdio.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char current_read;
    char buffer[1000];
    int buffer_size = 0;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {   
            while ((current_read = fgetc(input)) != EOF)
            {
                if (current_read != ' ')
                {
                    int no_copies = 1;
                    for (int i = 0; i < buffer_size; i++)
                    {
                        if (current_read == buffer[i])
                        {
                            no_copies = 0;
                            break;
                        }
                    }
                    
                    if (no_copies)
                    {
                        buffer[buffer_size] = current_read;
                        buffer_size++;
                    }
                }
            }

            buffer_size--;
            for (int i = 0; i < buffer_size; i++)
            {
                fputc(buffer[i], output);
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