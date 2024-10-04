//В диапазоне натуральных чисел от 2 до N определить, сколько из них кратны любому из чисел в диапазоне от 2 до 9.

#include <stdio.h>

void check_multiplicity(int multiplicity[8], int N)
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % (j + 2) == 0)
            {
                multiplicity[j]++;
            }
        }
    }
}

int main(void)
{
    int N, multiplicity[8] = {0};
    scanf("%d", &N);
    check_multiplicity(multiplicity, N);
    
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", i + 2);
        printf("%d\n", multiplicity[i]);
    }

    return 0;
}