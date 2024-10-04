//Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные,
// во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.

#include <stdio.h>

#define ARRAY_SIZE 10

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void print_non_zero_elements(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (array[i] != 0)
        {
            printf("%d ", array[i]);
        }
    }
}

void pick_positive_and_negative_elements(int input_array[], int arr_size, int positive_array[], int negative_array[])
{
    int positive_index = 0, negative_index = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (input_array[i] > 0)
        {
            positive_array[positive_index] = input_array[i];
            positive_index++;
        }
        else if (input_array[i] < 0)
        {
            negative_array[negative_index] = input_array[i];
            negative_index++;
        }
    }
}

int main(void)
{
    int array[ARRAY_SIZE], positive[ARRAY_SIZE], negative[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    pick_positive_and_negative_elements(array, ARRAY_SIZE, positive, negative);
    print_non_zero_elements(positive, ARRAY_SIZE);
    print_non_zero_elements(negative, ARRAY_SIZE);
    printf("\n");
    return 0;
}