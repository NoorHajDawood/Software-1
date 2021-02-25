#include <stdio.h>
int gcd(int a, int b)
{
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
int main(int argc, char const *argv[])
{
    printf("%d\n", gcd(125,50));
    return 0;
}