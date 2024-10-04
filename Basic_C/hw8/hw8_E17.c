//Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.

#include <stdio.h>

#define ARRAY_SIZE 10

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void print_solo_elements(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        int current_number = array[i];
        int counter = 0;
        for (int j = 0; j < arr_size; j++)
        {
            if (array[j] == current_number)
            {
                counter++;
            }
            if (counter > 1)
            {
                break;
            }
        }
        if (counter == 1)
        {
            printf("%d ", current_number);
        }
    }
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    print_solo_elements(array, ARRAY_SIZE);
    printf("\n");
    return 0;
}