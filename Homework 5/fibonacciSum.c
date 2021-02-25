#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number, f0 = 0, f1 = 1, sum = 0;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        sum += f1;
        f1 += f0;
        f0 = f1 - f0;
    }
    printf("%d", sum);
    return 0;
}
