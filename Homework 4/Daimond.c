#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number, spaces = 0;
    scanf("%d", &number);
    // print daimonds upper half
    spaces = number / 2;
    for (int i = 0; i < (number / 2); i++)
    {
        // print spaces for each row
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        spaces--;
        // print stars for each row
        for (int j = 0; j <= i * 2; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    // print daimonds lower half
    spaces = 0;
    for (int i = number/2; i >= 0; i--)
    {
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        spaces++;
        for (int j = 0; j <= i * 2; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
