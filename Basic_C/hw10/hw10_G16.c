//В файле input.txt дано предложение. Необходимо заменить все имена «Ling» на «Cao» и результат записать в файл output.txt.

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
            while (fscanf(input, "%[^\n]s", buffer) != EOF)
            {
                char letter = fgetc(input);
                if ((ptr = strstr(buffer, "Ling")) != NULL)
                {
                    if (strlen(buffer) == 4)
                    {
                        fprintf(output, "%s", "Cao");
                    }

                    else
                    {
                        int prefix_length = 0;
                        int length = 0;
                        int suffix_length = 0;

                        while ((ptr = strstr(buffer, "Ling")) != NULL)
                        {
                            prefix_length = ptr - buffer;
                            length = strlen(buffer);
                            suffix_length = length - prefix_length - 4;

                            for (int i = 0; i < prefix_length; i++)
                            {
                                fputc(buffer[i], output);
                            }
                            fprintf(output, "%s", "Cao");

                            char temp[strlen(buffer)];
                            strcpy(temp, buffer);
                            buffer[0] = 0;
                            strcpy(buffer, temp + prefix_length + 4);
                        }
                        
                        if (suffix_length != 0)
                        {
                            for (int i = 0; i < strlen(buffer); i++)
                            {
                                fputc(buffer[i], output);
                            }
                        }
                        
                    }
                }
                else
                {
                    fprintf(output, "%s", buffer);
                }
                fputc(' ', output);
                
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