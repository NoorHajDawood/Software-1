#include <stdio.h>

int seriesSum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i*n;
    return sum;
}

int main(int argc, char const *argv[])
{
    int nLow, nHigh, sum = 0;
    scanf("%d %d", &nLow, &nHigh);

    // swap values if nHigh is smaller than nLow
    if(nHigh < nLow)
    {
        nLow += nHigh;
        nHigh = nLow - nHigh;
        nLow -= nHigh;
    }
    
    while (nLow <= nHigh)
        sum += seriesSum(nLow++);
    printf("%d", sum);
    return 0;
}
