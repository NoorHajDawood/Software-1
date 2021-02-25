#include <stdio.h>

int panagram(char *s);
void f(int array[], int i, int j);
void reorderArray(int array[], int n);
unsigned long flipLong(unsigned long l);
int isGeometricArray(int arr[], int n);
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // //q2
    // printf("%d\n", panagram("Lovely C Programming"));

    // //q3
    // int array[] = {4, 1, -5, 1, 12, 4, 1, -5, 10, 1};
    // reorderArray(array, 10);
    // printArray(array, 10);

    // //q4
    // printf("%lu\n", flipLong(123456789));

    //q5
    int arr1[] = {2, 4, 8, 16, 32, 64}; // n=6
    int arr2[] = {3, 9, 36, 108};       // n=4
    int arr3[] = {1, 5, 25, 125, 125*5, 125*5*5}; // n=6
    printf("1: %d, 2: %d, 3: %d\n", isGeometricArray(arr1, 6), isGeometricArray(arr2, 4), isGeometricArray(arr3, 6));

    return 0;
}

int panagram(char *s)
{
    int letters[26] = {0};
    while (*s)
    {
        int small, big;
        if ((small = ('a' <= *s && *s <= 'z')) || (big = ('A' <= *s && *s <= 'Z')))
            letters[small ? *s - 'a' : *s - 'A']++;
        s++;
    }
    for (int i = 0; i < 26; i++)
        if (letters[i] == 0)
            return 0;
    return 1;
}

void f(int array[], int i, int j)
{
    int *pi = array + i;
    int *pj = array + j;
    int t;
    t = *pi;
    *pi = *pj;
    *pj = t;
}

void reorderArray(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
                f(array, ++i, j);
        }
    }
}

unsigned long flipLong(unsigned long l)
{
    int m = 0;
    do
        m = (m*10) + (l%10);
    while (l/=10);
    return m;
}

int isGeometricArray(int arr[], int n) 
{
    int q = arr[n-1] / arr[n-2];
    if (q <= 1)
        return -1;
    if(n == 2)
        return q;
    int result = isGeometricArray(arr, n-1);
    return q == result ? q : -1;
}