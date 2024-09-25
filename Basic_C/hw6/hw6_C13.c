//Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
//cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... (x в радианах)

#include <stdio.h>

float power(float n, int p)
{
    if (p == 0)
    {
        return 1.0;
    }
    else
    {
        float result = 1.0;
        for (int i = 0; i < p; i++)
        {
            result *= n;
        }
        return result;
    }
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        int result = 1;
        for (int i = 1; i <= n; i++)
        {
            result *= i;
        }
        return result;
    }
}

float cosinus(float x)
{
    float x_rad = x*3.14159/180;
    float cos = 1.0;
    int current_power = 2;
    float temp;
    int sign = -1;

    do
    {
        temp = sign*power(x_rad, current_power)/factorial(current_power);
        cos += temp;
        current_power += 2;
        sign *= -1;
    } while (temp*sign*(-1) >= 0.001);
    
    return cos;
}

int main(void)
{
    float degrees;
    scanf("%f", &degrees);

    printf("%.3f\n", cosinus(degrees));
    return 0;
}