#include <stdio.h>

int sumDigits(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int sumDigN1 = sumDigits(n1), sumDigN2 = sumDigits(n2);
    if(!sumDigN2 || (sumDigN1%sumDigN2))
        printf("Not Divides");
    else
        printf("Divides");
    return 0;
}
