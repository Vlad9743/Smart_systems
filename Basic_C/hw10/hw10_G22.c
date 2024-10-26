//Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи ли два английских слова по звучанию.
// На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код.
// Если коды двух слов совпадают, то слова, как правило, звучат похоже.

//Вам требуется реализовать этот алгоритм. Он работает так:

//Первая буква слова сохраняется.
//В остальной части слова:
//буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются;
// оставшиеся буквы (согласные) заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
//1: b, f, p, v
//2: c, g, j, k, q, s, x, z
//3: d, t
//4: l
//5: m, n
//6: r
//Любая последовательность одинаковых цифр сокращается до одной такой цифры. Итоговая строка обрезается до первых четырёх символов.
//Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.
//Примеры:
//аmmonium → ammnm → a5555 → a5 → a500
//implementation → implmnttn → i51455335 → i514535 → i514

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char letter;
    char buffer[100];

    FILE *input, *output;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input != NULL)
    {
        if (output != NULL)
        {   
            fscanf(input, "%s", buffer);
            
            int length = strlen(buffer);

            if (length > 0)
            {
                // step 1 - word to code
                char temp[100];
                int temp_size = 1;
                temp[0] = buffer[0];

                for (int i = 1; i < length; i++)
                {
                    if (strchr("aehiouwy", buffer[i]) != NULL)
                    {
                        continue;
                    }
                    else if (strchr("bfpv", buffer[i]) != NULL)
                    {
                        temp[temp_size] = '1';
                        temp_size++;
                    }
                    else if (strchr("cgjkqsxz", buffer[i]) != NULL)
                    {
                        temp[temp_size] = '2';
                        temp_size++;
                    }
                    else if (strchr("dt", buffer[i]) != NULL)
                    {
                        temp[temp_size] = '3';
                        temp_size++;
                    }
                    else if (buffer[i] == 'l')
                    {
                        temp[temp_size] = '4';
                        temp_size++;
                    }
                    else if (strchr("mn", buffer[i]) != NULL)
                    {
                        temp[temp_size] = '5';
                        temp_size++;
                    }
                    else if (buffer[i] == 'r')
                    {
                        temp[temp_size] = '6';
                        temp_size++;
                    }
                }

                //step 2 - shorten
                char temp_short[4] = {'0', '0', '0', '0'};
                char short_size = 1;
                temp_short[0] = temp[0];

                for (int i = 1; i < temp_size && i <= 4; i++)
                {
                    if (temp[i] != temp_short[short_size - 1])
                    {
                        short_size++;
                        temp_short[short_size - 1] = temp[i];
                    }
                }

                //step 3 - output
                int i = 0;
                for (i; i < 4; i ++)
                {
                    fputc(temp_short[i], output);
                }
    
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