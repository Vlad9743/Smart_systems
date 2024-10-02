//Составить рекурсивную функцию
//Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.

#include <stdio.h>

void print_a_to_b(int a, int b)
{
    printf("%d ", a);
    if (a < b)
    {
        print_a_to_b(a + 1, b);
    }
    else if (a > b)
    {
        print_a_to_b(a - 1, b);
    }
}
 
int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    print_a_to_b(a, b);
    printf("\n");
    return 0;
}