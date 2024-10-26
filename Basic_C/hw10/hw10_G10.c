//В файле input.txt дана строка слов, разделенных пробелами.
// Найти самое длинное слово и вывести его в файл output.txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char current_word[1000];
    char longest_word[1000];
    int current_length;
    int max_length = 0;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {
            while (fscanf(input, "%s", current_word) != EOF)
            {
                current_length = strlen(current_word);
                if (current_length > max_length)
                {
                    max_length = current_length;
                    strcpy(longest_word, current_word);
                }
            }
            fprintf(output, "%s", longest_word);

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