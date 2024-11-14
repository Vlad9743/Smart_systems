//Известно, что шахматная доска имеет размерность 8х8 и состоит из клеток 2х цветов,
//например, черного и белого (см. рисунок). Каждая клетка имеет координату, состоящую из буквы и цифры.
// Горизонтальное расположение клетки определяется буквой от A до H, а вертикальное – цифрой от 1 до 8.
// Заметим, что клетка с координатой А1 имеет черный цвет. Требуется по заданной координате определить цвет клетки.

#include <stdio.h>

int main(void)
{
    char position[2];
    scanf("%s", position);
    
    if ((position[0] % 2) == (position[1] % 2))
    {
        printf("BLACK\n");
    }
    else
    {
        printf("WHITE\n");
    }

    return 0;
}