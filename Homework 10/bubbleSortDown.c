#include <stdio.h>

void bubbleSortDown(int arr[], int n);
void selectionSortDown(int arr[], int n);
void insertionSortDown(int arr[], int n);
void swapInt(int *x, int *y);
int findMax(int arr[], int start, int size);
void printArray(int arr[], int n);
int findInsertPoint(int arr[], int number, int start, int size);
void shiftArray(int arr[], int start, int size);

int main(int argc, char const *argv[])
{
    int n;
    int arr[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    bubbleSortDown(arr, n);
    // selectionSortDown(arr, n);
    // insertionSortDown(arr, n);
    printArray(arr, n);
    return 0;
}

void bubbleSortDown(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                swapInt(arr + j, arr + j - 1);
            }
        }
    }
}

void selectionSortDown(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        swapInt(arr + findMax(arr, i, n), arr + i);
    }
}

void insertionSortDown(int arr[], int n)
{
    for (int i = n-1; i; i--)
    {
        int temp = arr[i-1];
        int insertPoint = findInsertPoint(arr, temp, i, n);
        shiftArray(arr , i-1, insertPoint+1);
        arr[insertPoint] = temp;
    }
    
}

int findInsertPoint(int arr[], int number, int start, int size)
{
    for (int i = size - 1; i >= start; i--)
    {
        if(arr[i] > number)
        {
            return i;
        }
    }
    return start-1;
}

void shiftArray(int arr[],int start, int size)
{
    for(int i = start; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
}

void swapInt(int *x, int *y)
{
        // this was causing trouble when swapping arr+i with arr+i, it would result with arr[i] having 0 no matter what
        // *x += *y;
        // *y = *x - *y;
        // *x -= *y;
        int temp = *x;
        *x = *y;
        *y = temp;
}

int findMax(int arr[], int start, int size)
{
    int maxIndex = start;
    while (++start < size)
    {
        if (arr[maxIndex] < arr[start])
        {
            maxIndex = start;
        }
    }
    return maxIndex;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}