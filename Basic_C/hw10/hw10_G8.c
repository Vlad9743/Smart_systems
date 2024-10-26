//В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
// Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
// Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
// Вывести массив по возрастанию в файл output.txt.

#include <stdio.h>

void sort_array(int array[], int array_size)
{
    for (int i = 0; i < array_size - 1; i++)
    {
        for (int j = 0; j < array_size - 1 - i; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char letter;
    int array[1000] = {0};
    int array_size = 0;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {
            int number = 0;
            int reading_num = 0;
            while ((letter = fgetc(input)) != EOF)
            {
                if (letter >= '0' && letter <= '9')
                {
                    reading_num = 1;
                    number *= 10;
                    number += (letter - '0');
                }
                else
                {
                    if (reading_num)
                    {
                        reading_num = 0;
                        array[array_size] = number;
                        number = 0;
                        array_size++;
                    }
                }
            }

            sort_array(array, array_size);

            for (int i = 0; i < array_size; i++)
            {
                fprintf(output, "%d ", array[i]);
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