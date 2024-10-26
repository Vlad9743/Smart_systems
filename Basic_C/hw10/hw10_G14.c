//В файле input.txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие output.txt, где останутся имя и фамилия
//Pupkin Vasiliy Ivanovich
//Hello, Vasiliy Pupkin!

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char name[50];
    char surname[50];
    char result[150] = "Hello, ";

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {   
            fscanf(input, "%s", surname);
            fscanf(input, "%s", name);

            strcat(result, name);
            strcat(result, " ");
            strcat(result, surname);
            strcat(result, "!");

            fprintf(output, "%s", result);

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

