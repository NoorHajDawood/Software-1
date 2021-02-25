#include <stdio.h>

int sumArray(int a[], int n);

int main(int argc, char const *argv[])
{
    int arr[20] = {0}, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    printf("%d", sumArray(arr, n));   
    return 0;
}

int sumArray(int a[], int n)
{
    if(n == 0)
        return 0;
    return a[n-1] + sumArray(a, n-1);
}