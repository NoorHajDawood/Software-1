#include <stdio.h>

void oddity(int arr[], int n);
void inverseArray(int *arr, int n);

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int arr[] = {11,24,-13,2,55,123,-4,28,17,0,12};
    int arr1[] = {1,2,3,4,5,6};
    inverseArray(arr1,6);
    printArray(arr1,6);
    oddity(arr,11);
    printArray(arr,11);
    return 0;
}


void oddity(int arr[], int n)
{
    for (int j = 0; j < n; j++)    
    {
        for (int i = n-1; i > 0; i--)
        {
            if (arr[i] % 2)
            {
                int t = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = t;
            }
        }
    }
}

void inverseArray(int *arr, int n)
{
    if(n<=0)
        return;
    int t = *arr;
    *arr = arr[n-1];
    arr[n-1] = t;
    inverseArray(arr+1,n-2);
}