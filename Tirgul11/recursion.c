#include <stdio.h>
#include <string.h>

int myPow(int x, int n); //return xn
int digits(int n);       //12345 ==returns==> 5
int reverseNum(int n);   //12345 ==returns==> 54321
char *unVowel(char *s);
int countWords(char *s);
int isPalindromeString(char *s);
int binarySearch(int array[], int strt, int end, int search);
void Hanoi(int n, int p, int q, int r);
int max_set(int arr[], int size, int maxval, int len);

int main(int argc, char const *argv[])
{
    printf("1: %d\n", myPow(5, 3));
    printf("2: %d\n", digits(12345));
    printf("3: %d\n", reverseNum(12345));
    char s[] = "Heello World It's A Wonderful Day";
    printf("4: %s\n", unVowel(s));
    printf("5: %d\n", countWords("Hello World It's A Wonderful Day"));
    char s1[] = "Hello World";
    printf("6: %d  --- Hello World\n", isPalindromeString(s1));
    char s2[] = "abccba";
    printf("6: %d  --- abccba\n", isPalindromeString(s2));
    char s3[] = "abcba";
    printf("6: %d  --- abcba\n", isPalindromeString(s3));
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("7: %d\n", binarySearch(arr, 0, 9, 3));

    Hanoi(3, 'a', 'b', 'c');

    int arr1[] = {45,7,89,109,3,2,11,98,5};
    printf("%d\n", max_set(arr1, 9, 0, 0));

    return 0;
}

int myPow(int x, int n)
{
    if (n == 0)
        return 1;
    return x * myPow(x, n - 1);
}

int digits(int n)
{
    if (n == 0)
        return 0;
    return 1 + digits(n / 10);
}

int reverseNum(int n)
{
    if (n == 0)
        return 0;
    return reverseNum(n / 10) + (n % 10) * myPow(10, digits(n) - 1);
}

char *unVowel(char *s)
{
    if (*s == '\0')
        return s;
    unVowel(s + 1);
    switch (*s)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        strcpy(s, s + 1);
        break;
    }
    return s;
}

int countWords(char *s)
{
    while (*s == ' ')
    {
        s++;
    }
    if (*s == '\0')
        return 0;
    while (*s != ' ')
    {
        s++;
    }
    return 1 + countWords(s++);
}

int isPalindromeString(char *s)
{
    if (*s == '\0')
        return 1;

    if (*s != s[strlen(s) - 1])
        return 0;

    char temp = s[strlen(s) - 1];
    s[strlen(s) - 1] = '\0';

    int rc = isPalindromeString(s + 1);
    s[strlen(s) - 1] = temp;
    return rc;
}

int binarySearch(int array[], int strt, int end, int search)
{
    if (end < strt)
        return -1;
    if (array[(strt + end) / 2] == search)
        return (strt + end) / 2;
    if (array[(strt + end) / 2] > search)
        return binarySearch(array, strt, (strt + end) / 2 - 1, search);
    if (array[(strt + end) / 2] < search)
        return binarySearch(array, (strt + end) / 2 + 1, end, search);
}

void Hanoi(int n, int p, int q, int r)
{
    if (n == 1)
    {
        printf("move disk from pole %d to pole %d\n", p, r);
        return;
    }
    Hanoi(n - 1, p, r, q);
    printf("move disk from pole %d to pole %d\n", p, r);
    Hanoi(n - 1, q, p, r);
}

int max_set(int arr[], int size, int maxValue, int length)
{
    if (size == 0)
        return length;

    int maxLength;
    maxLength = max_set(arr+1, size-1, maxValue, length); // length witohut *arr

    if (*arr > maxValue) // if *arr can be in the set
    {
        int temp = max_set(arr+1, size-1, *arr, length + 1); // length with *arr
        if (temp > maxLength) // check if its best to include *arr or not
            maxLength = temp;
    }

    return maxLength;
}