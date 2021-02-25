#include <stdio.h>

int unique(int array[], int n);
void f(int array[], int i, int j);
int orderParity(int array[], int n);
void mirror(char *s);
long long modifiedFibo(int t0, int t1, int n);
long long modifiedFibo_asaf(int t0, int t1, int n);
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
    //q2
    // int arr[100], n;
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", arr + i);
    // }
    // printf("%d\n", unique(arr, n));

    //q3
    // int array[] = {1, 10, 5, 2, 8, 3, 7, 9, 5, 1, 4};
    // printf("%d: ", orderParity(array, 11));
    // printArray(array, 11);

    //q4
    // char str[256] = "123456789";
    // mirror(str);
    // printf("%s\n", str);

    //q5
    printf("%lld\n", modifiedFibo(1, 3, 4));

    return 0;
}

int unique(int array[], int n) // needs fixing
{
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = 0; flag && j < n; j++)
        {
            if (i != j && array[i] == array[j])
                flag = 0;
        }
        if (flag)
            return array[i];
    }
}

void f(int array[], int i, int j)
{
    int *p;
    for (p = array + j; p > array + i; --p)
        *p = *(p - 1);
}

int orderParity(int array[], int n)
{
    int counter = 0;
    for (int i = 0; i < n && counter < n; i++)
    {
        if (array[i] % 2)
        {
            counter++;
            int tmp = array[n - 1];
            f(array, i, n - 1);
            array[i] = tmp;
            i--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2)
            return i;
    }
}

void mirror(char *s)
{
    char *p;
    int t;
    for (p = s; *p; p++)
        ;
    while (s < p)
    {
        t = *s;
        *s++ = *--p;
        *p = t;
    }
}

long long modifiedFibo(int t0, int t1, int n)
{
    if (n == 0)
        return t0;
    if (n == 1)
        return t1;
    return modifiedFibo(t1, t0 + t1 * t1, n - 1);
}

long long modifiedFibo_asaf(int t0, int t1, int n)
{
    if (n == 0)
        return t0;
    if (n == 1)
        return t1;
    return modifiedFibo_asaf(t0, t1, n - 2) + modifiedFibo_asaf(t0, t1, n - 1) * modifiedFibo_asaf(t0, t1, n - 1);
}