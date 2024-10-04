//Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. 
//Необходимо изменить считанный массив и напечатать его одним циклом.

#include <stdio.h>

#define ARRAY_SIZE 10

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void swap_elements(int *elem1, int *elem2)
{
    int temp;
    temp = *elem2;
    *elem2 = *elem1;
    *elem1 = temp;
}

void invers_halves_and_print(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (i == 0 || i == 5)
        {
            swap_elements(array+i, array+i+4);
        }

        if (i == 1 || i == 6)
        {
            swap_elements(array+i, array+i+2);
        }

        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    invers_halves_and_print(array, ARRAY_SIZE);
    return 0;
}