#include <stdio.h>

int arraySum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

void arrayShiftRight(int arr[], int size)
{
    int tmp = arr[size - 1];
    for (int i = size - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = tmp;
}

int main(int argc, char const *argv[])
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        printf("%d>", i);
        scanf("%d", &arr[i]);
    }
    printf("%d\n", arraySum(arr, 10));
    arrayShiftRight(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d: %d\t", i, arr[i]);
    }

    return 0;
}
