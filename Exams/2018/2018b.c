#include <stdio.h>
#include <string.h>

int isArithmeticArray(int arr[], int n);
int f(int *s, int *t);
int balanceArray(int arr[], int n);
int anagram(char *s1, char *s2);
int my_strlen(char *p);

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 7, 10, 13};
    printf("%d\n", isArithmeticArray(arr, 5));

    int arr2[] = {1};
    printf("%d\n", balanceArray(arr2, 1));

    char str1[] = "listen";
    char str2[] = "silent";
    printf("%d\n", anagram(str1,str2));

    printf("%d\n", my_strlen(str1));
    return 0;
}

int isArithmeticArray(int arr[], int n)
{
    int d = arr[1] - arr[0];
    if (n == 2)
        return d > 0 ? d : -1;
    return (d == isArithmeticArray(arr + 1, n - 1) ? d : -1);
}

int f(int *s, int *t)
{
    int sum = 0;
    do
        sum += *s;
    while (s++ < t);
    return sum;
}

int balanceArray(int arr[], int n)
{
    if (n == 1)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            if (f(arr + i + 1, arr + n - 1) == 0)
                return i;
        if (i == n - 1)
            if (f(arr, arr + i - 1) == 0)
                return i;
        if (f(arr + i + 1, arr + n - 1) == f(arr, arr + i - 1))
            return i;
    }
    return -1;
}
int anagram(char *s1, char *s2)
{
    int count1['z' - 'a' + 1] = {0};
    int count2['z' - 'a' + 1] = {0};
    int size = 'z' - 'a' + 1;
    for (int i = 0; s1[i]; i++)
    {
        if ('a' <= s1[i] && s1[i] <= 'z')
            count1[s1[i] - 'a']++;
    }
    for (int i = 0; s2[i]; i++)
    {
        if ('a' <= s2[i] && s2[i] <= 'z')
            count2[s2[i] - 'a']++;
    }
    for (int i = 0; i < size; i++)
    {
        if (count1[i] != count2[i])
            return 0;
    }
    return 1;
}
int my_strlen(char *p)
{
    char *q=p;
    for(;;)
        switch (*p)
        {
        case 0: return p-q;
        default: p++;
        }
}