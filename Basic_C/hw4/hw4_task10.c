//Ввести номер месяца и вывести название времени года  (используйте switch)

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int16_t n;
    scanf("%hd", &n);

    switch (n)
    {
    case 1:
        printf("winter\n");
        break;

    case 2:
        printf("winter\n");
        break;

    case 3:
        printf("spring\n");
        break;

    case 4:
        printf("spring\n");
        break;

    case 5:
        printf("spring\n");
        break;

    case 6:
        printf("summer\n");
        break;

    case 7:
        printf("summer\n");
        break;

    case 8:
        printf("summer\n");
        break;

    case 9:
        printf("autumn\n");
        break;

    case 10:
        printf("autumn\n");
        break;

    case 11:
        printf("autumn\n");
        break;

    case 12:
        printf("winter\n");
        break;
    
    default:
        printf("wrong input\n");
        break;
    }
}