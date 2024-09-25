//Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
//sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)

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

float sinus(float x)
{
    float x_rad = x*3.14/180;
    float sin = x_rad;
    int current_power = 3;
    float temp;
    int sign = -1;

    do
    {
        temp = sign*power(x_rad, current_power)/factorial(current_power);
        sin += temp;
        current_power += 2;
        sign *= -1;
    } while (temp*sign*(-1) >= 0.001);
    
    return sin;
}

int main(void)
{
    float degrees;
    scanf("%f", &degrees);

    printf("%.3f\n", sinus(degrees));
    return 0;
}