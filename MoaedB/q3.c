#include <stdio.h>
void f(int *a, int n)
{
    for (int i = 0; i < n - 1; ++i, ++a)
    {
        int t = *a;
        *a = *(a + 1);
        *(a + 1) = t;
    }
}

void mirrorArray(int *arr, int n)
{
    while(n > 0)
    {
        f(arr, n);
        n--;
    }
}


void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2 ,3 ,4};
    mirrorArray(arr, 4);
    printArray(arr,4);
    return 0;
}
