//Определить уравнение прямой по координатам двух точек
// Вывести коэффициенты k и b

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t x1, y1, x2, y2;
    float k, b;

    scanf("%hd%hd%hd%hd", &x1, &y1, &x2, &y2);

    k = (float)(y2 - y1)/(x2 - x1);
    b = y1 - k*x1;

    printf("%.2f %.2f\n", k, b);
    return 0;
}