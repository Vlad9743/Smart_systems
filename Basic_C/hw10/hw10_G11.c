//В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'.
// Ответ записать в файл output.txt.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char word[100];
    int a_word_counter = 0;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {   
            while (fscanf(input, "%s", word) != EOF)
            {
                int length = strlen(word);
                if (word[length - 1] == 'a')
                {
                    a_word_counter++;
                }
            }
            fprintf(output, "%d", a_word_counter);

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