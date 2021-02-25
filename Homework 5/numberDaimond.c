#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number;
    scanf("%d", &number);
    int spaces = number;
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        spaces--;
        for (int j = i; j > 0; j--)
        {
            printf("%d", j);
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    for (int i = number; i >= 0; i--)
    {
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        spaces++;
        for (int j = i; j > 0; j--)
        {
            printf("%d", j);
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    
    return 0;
}
