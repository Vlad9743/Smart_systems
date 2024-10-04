//Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.

#include <stdio.h>

void print_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", array[i]);
    }
}

int count_digits(int number)
{   
    int counter = 0;
    while (number > 0)
    {
        number /= 10;
        counter++;
    }
    return counter;
}

void number_to_array(int number, int array[], int arr_size)
{
    for (int i = arr_size - 1; i >= 0; i--)
    {
        array[i] = number % 10;
        number /= 10;
    }
}

int main(void)
{
    int number;
    scanf("%d", &number);

    int number_length = count_digits(number);
    int number_array[number_length];

    number_to_array(number, number_array, number_length);
    print_array(number_array, number_length);
    printf("\n");
    return 0;
}