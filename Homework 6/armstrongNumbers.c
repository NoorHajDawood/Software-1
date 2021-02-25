#include <stdio.h>

int digits(int n);
int power(int n, int e);
int isArmstrong(int n);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    printf("%s", isArmstrong(n) ? "Armstrong" : "Not Armstrong");
    return 0;
}

int digits(int n)
{
    int counter = 0;
    do
    {
        counter++;
        n /= 10;
    } while (n);
    return counter;
}

int power(int n, int e)
{
    int total = 1;
    for (int i = 0; i < e; i++)
    {
        total *= n;
    }
    return total;
}

int isArmstrong(int n)
{
    int sum = 0, digitsCount = digits(n), tmpNumber = n;
    while (tmpNumber)
    {
        sum += power(tmpNumber % 10, digitsCount);
        tmpNumber /= 10;
    }
    return sum == n ? 1 : 0;
}