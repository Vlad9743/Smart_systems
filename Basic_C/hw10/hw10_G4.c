//В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом. 
//Найдите только те символы слов, которые встречаются в обоих словах только один раз. 
//Напечатайте их через пробел в файл output.txt в лексикографическом порядке.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char word_1[100];
    char word_2[100];
    char result[50];
    int result_size = 0;
    int counter_1 = 0;
    int counter_2 = 0;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {
            fscanf(input, "%s", word_1);
            fscanf(input, "%s", word_2);
            int length_1 = strlen(word_1);
            int length_2 = strlen(word_2);

            for (int i = 0; i < length_1; i++)
            {
                for (int j = 0; j < length_1; j++)
                {
                    if (word_1[i] == word_1[j])
                    {
                        counter_1++;
                    }
                }

                for (int k = 0; k < length_2; k++)
                {
                    if (word_1[i] == word_2[k])
                    {
                        counter_2++;
                    }
                }

                if (counter_1 == 1 && counter_2 == 1)
                {
                    result[result_size] = word_1[i];
                    result_size++;
                }

                counter_1 = 0;
                counter_2 = 0;
            }

            for (int i = 0; i < result_size; i++)
            {
                fputc(result[i], output);
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