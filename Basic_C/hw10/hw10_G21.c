//Cia очень любит равносторонние треугольники. Он все время выкладывает их из камней.
// Ling дал Cia камни и попросил его составить такой треугольник если это возможно.
//Помогите Cia сложить треугольник используя все камни или напечатайте слов NO, если это невозможно.
//Во входном файле input.txt записано некоторое количество символов * (камней).
//Необходимо построить равносторонний треугольник используя все символы * и символ пробел,
//записать ответ в выходной файл output.txt. Между соседними символами * строго один пробел.
// Если треугольник невозможно составить, используя все камни, то необходимо записать единственное слово NO в файл output.txt.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char letter;
    int stones_number = 0;

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {   
            while ((letter = fgetc(input)) != EOF)
            {   
                if (letter == '*')
                {
                    stones_number++;
                }
            }

            if (stones_number != 0)
            {
                int temp = stones_number;
                int i = 1;
                while (temp > 0)
                {
                    temp -= i;
                    i++;
                }
                i--;
        
                int length = 2*i - 1;

                if (temp == 0)
                {
                    for (int j = 1; j <= i; j++)
                    {
                        for (int k = 1; k <= i - j; k++)
                        {
                            fputc(' ', output);
                        }

                        for (int k = 1; k <= j; k++)
                        {
                            fputc('*', output);
                            fputc(' ', output);
                        }

                        fputc('\n', output);
                    }
                }
                else
                {   
                    fprintf(output, "%s", "NO");
                }
            }
            else
            {   
                fprintf(output, "%s", "NO");
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