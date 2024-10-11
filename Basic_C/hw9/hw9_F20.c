//Дан целочисленный массив из 10 элементов. 
//Необходимо определить количество четных и нечетных чисел.
//Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число
//на произведение нечетных цифр в его десятичной записи. Если количество нечётных чисел 
//больше или равно количеству чётных, заменить каждое чётное число на произведение чётных цифр в его десятичной записи.

#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE 10

void read_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

void print_array(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

void count_odds_and_evens(int size, int array[], int results[2])
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            results[1]++;
        }
        else
        {
            results[0]++;
        }
    }
}

int odd_digits_mult(int number)
{
    int mult = 1;
    while (number > 0)
    {
        if ((number % 10) % 2 != 0)
        {
            mult *= (number % 10);
        }
        number /= 10;
    }

    return mult;
}

int even_digits_mult(int number)
{
    int mult = 1;
    while (number > 0)
    {
        if ((number % 10) % 2 == 0)
        {
            mult *= (number % 10);
        }
        number /= 10;
    }

    return mult;
}

int main(void)
{
    int array[ARRAY_SIZE];
    read_array(ARRAY_SIZE, array);
    
    int odds_and_evens[2] = {0};// [0] - number of odds, [1] - number of evens
    count_odds_and_evens(ARRAY_SIZE, array, odds_and_evens);

    if (odds_and_evens[1] > odds_and_evens[0])
    {
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (array[i] % 2 != 0)
            {
                array[i] = odd_digits_mult(array[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (array[i] % 2 == 0)
            {
                array[i] = even_digits_mult(array[i]);
            }
        }
    }

    print_array(ARRAY_SIZE, array);
    printf("\n");

    return 0;
}