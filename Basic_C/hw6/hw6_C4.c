//Описать функцию вычисления f(x) по формуле:
//f(x)= x*x при -2 ≤ x < 2;
//x*x+4x+5 при x ≥ 2;
//4 при x < -2.
//Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.

#include <stdio.h>
#include <inttypes.h>

int equation(int x)
{
    if (x >= 2)
    {
        return x*x + 4*x + 5;
    }
    else if (x < -2)
    {
        return 4;
    }
    else
    {
        return x*x;
    }
}
 
int main(void)
{
    int32_t number, temp, max = INT32_MIN;
    int32_t n = 5;//number of numbers

    for (int i = 0; i < n; i++)
    {   
        scanf("%d", &number);
        temp = equation(number);
        if (temp > max)
        {
            max = temp;
        }
    }
    printf("%d\n", max);
    return 0;
}