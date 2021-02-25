#include <stdio.h>

unsigned long flipLong(unsigned long l);
int lipogram(char *s, char letters[]);
int sumPrimes(int low, int high);
int isPrime(int num);
int f(char *s);
int longestWord(char *s);

int main(int argc, char const *argv[])
{
    printf("%d\n", sumPrimes(3, 26));
    char str[] = "It is a stringasda withabcsd smallest and largest word";
    printf("%d\n", longestWord(str));
    char str2[] = "it might be that to surrender to happiness was to accept defeat, but it was a defeat better than many victories";
    char letters[256];
    printf("%d\n",lipogram(str2, letters));
    printf("%s\n", letters);
    return 0;
}

unsigned long flipLong(unsigned long l)
{
    int m = 0;
    do
        m = (m * 10) + (l % 10);
    while (l /= 10);
    return m;
}
int sumPrimes(int low, int high)
{
    if (low > high)
        return 0;
    return sumPrimes(low + 1, high - 1) + (isPrime(high) ? high : 0) + (isPrime(low) ? low : 0) - (low == high && isPrime(low) ? low : 0);
}
int isPrime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int f(char *s)
{
    int count = 0;
    while (*s && *s++ != ' ')
        ++count;
    return count;
}
int longestWord(char *s)
{
    int max = 0, current = 0;
    while (*s)
    {
        current = f(s);
        if (max < current)
        {
            max = current;
        }
        s += current + 1;
    }
    return max;
}

int lipogram(char *s, char letters[])
{
    int count['z'-'a'+1] = {0};
    while (*s)
    {
        if(('a' <= *s && *s <= 'z') || ('A' <= *s && *s <= 'Z'))
            count[ (('a' <= *s && *s <= 'z') ? *s : *s + 'a' - 'A') - 'a']++;
        s++;
    }
    int j = 0;
    for (int i = 0; i <= 'z'-'a'; i++)
    {
        if (count[i] == 0)
            letters[j++] = i+'a';
    }
    letters[j] = '\0';
    return j;
}