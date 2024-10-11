//Дана строка состоящая из маленьких латинских букв 'a'..'z'.
//В конце строки точка. Необходимо заменить повторяющиеся буквы на <буква><количество повторений>

#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 100

void read_string(char st[])
{
    char letter;
    int i = 0;
    
    while ((letter = getchar()) != '\n' && i < STRING_LENGTH)
    {
        st[i] = letter;
        i++;
    }
}

void compress_string(char original_string[], char compressed_string[])
{   
    int original_length = strlen(original_string);
    int original_index = 1;
    int compressed_index = 0;
    int counter = 0;

    for (original_index; original_index < original_length; original_index++)
    {
        if (original_string[original_index - 1] != original_string[original_index])
        {
            compressed_string[strlen(compressed_string)] = original_string[original_index - 1];

            char temp_string[5];
            sprintf(temp_string, "%d", counter + 1);
            strcat(compressed_string, temp_string);
            counter = 0;
            
        }
        else
        {
            counter++;
        }
    }
}


int main(void)
{
    char original_st[STRING_LENGTH];
    read_string(original_st);

    char compressed_st[STRING_LENGTH] = "";
    compress_string(original_st, compressed_st);
    printf("%s\n", compressed_st);

    return 0;
}
