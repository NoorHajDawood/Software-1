#include <stdio.h>

int leadingDigit(int n)
{
    do
    {
        if(!(n/10))
            return n;
        n /= 10;
    } while (n);
}

int main(int argc, char const *argv[])
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d", leadingDigit(n1)+leadingDigit(n2));
    return 0;
}
