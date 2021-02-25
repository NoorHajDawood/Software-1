#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number, numerator, denominator;
    printf("Integer: ");
    scanf("%d", &number);
    printf("Numerator: ");
    scanf("%d", &numerator);
    printf("Denominator: ");
    scanf("%d", &denominator);
    printf("Value as a decimal float: %f", number + ((float)numerator) / denominator);
    return 0;
}
