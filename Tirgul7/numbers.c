#include <stdio.h>

int countDigit(int a, int d)
{
    int counter = 0;
    while (a)
    {
        if (a % 10 == d)
            counter++;
        a /= 10;
    }
    return counter;
}

int numberToDigitCountNumber(int a)
{
    int result = 0;
    for (int i = 9; i > 0; i--)
    {
        result = result*10 + countDigit(a,i);
    }
    return result;
}

int areNumericAnagram(int a, int b)
{
    return numberToDigitCountNumber(a) == numberToDigitCountNumber(b);
}

int digitSortNoRepetations(int a)
{
    int sorted = 0;
    for(int i = 1; i <= 9; i++)
    {
        if(countDigit(a,i))
            sorted = sorted*10 + i;
    }
    return sorted;
}

int digitSort(int a)
{
    int sorted = 0;
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 0; j < countDigit(a,i); j++)
            sorted = sorted*10 + i;
    }
    return sorted;
}
int main(int argc, char const *argv[])
{
    int a, d, b;
    scanf("%d %d %d", &a, &d, &b);
    printf("1: %d\n2: %d\n3: %d\n4: %d\n5: %d", countDigit(a,d), numberToDigitCountNumber(a), areNumericAnagram(a,b), digitSortNoRepetations(a), digitSort(a));
    return 0;
}
