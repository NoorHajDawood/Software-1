#include <stdio.h>

int mul(int a, int b)
{
    return a * b;
}

int power(int b, int e)
{
    int result = 1;
    for (int i = 0; i < e; i++)
    {
        result *= b;
    }
    return result;
}

int isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (!(n % i))
            return 0;
    }
    return 1;
}

float freedomTempretuare(int c)
{
    return (c * 9.F/5) + 32;
}

void factors(int n){
    for (int i = 2; i <= n/2; i++)
    {
        if(!(n%i))
            if(isPrime(i))
                printf("%d ", i);
    }
    
}

int main(int argc, char const *argv[])
{
    printf("mul: %d\npower: %d\nisPrime: %d\nfreedomTempreture: %f\n", mul(5, 3), power(5, 3), isPrime(31), freedomTempretuare(21));
    factors(100);
    return 0;
}
