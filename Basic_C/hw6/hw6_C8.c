//Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее использования.
//Дана строка состоящая из английских букв, пробелов и запятых. В конце строки символ точка.
#include <stdio.h>
#include <inttypes.h>

char change_letter(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        letter -= 32;
    }
    return letter;
}
 
int main(void)
{
    char letter;

    do
    {
        scanf("%c", &letter);
        if(letter == '.')
        {
            break;
        }
        printf("%c", change_letter(letter));
    } while (letter != '.');
    printf("\n");

    return 0;
}