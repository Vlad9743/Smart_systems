//Дана монотонная последовательность, в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,… 
//Выведите первые n членов этой последовательности. Только один цикл for.

#include <stdio.h>

void multiprint(int n, int k)
{   
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", k);
        n--;
        if (n == 0)
        {
            return;
        }
    }
    multiprint(n, k + 1);
}

int main(void)
{
    int number;
    scanf("%d", &number);
    multiprint(number, 1);
    printf("\n");
    return 0;
}