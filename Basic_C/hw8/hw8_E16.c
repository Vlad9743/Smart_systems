//Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.
#include <stdio.h>

#define ARRAY_SIZE 10

void fill_array(int array[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int find_most_frequent_number(int array[], int arr_size)
{
    int most_frequent_number = array[0];
    int max_frequency = 1;

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
        }
        if (counter > max_frequency)
        {
            max_frequency = counter;
            most_frequent_number = current_number;
        }
    }
    return most_frequent_number;    
}

int main(void)
{
    int array[ARRAY_SIZE];
    fill_array(array, ARRAY_SIZE);
    int number = find_most_frequent_number(array, ARRAY_SIZE);
    printf("%d\n", number);
    return 0;
}