#include <stdio.h>

int firstApperance(int *arr, int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number)
            return i;
    }
    return -1;
}

int lastApperance(int *arr, int size, int number)
{
    for (int i = size - 1; i > 0; i--)
    {
        if (arr[i] == number)
            return i;
    }
    return -1;
}

int sumFromTo(int *arr, int first, int last)
{
    if(first == last)
        return 0;
    int sum = 0;
    for (int i = first; i <= last; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int arr[20], size, number;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &number);
    printf("%d", sumFromTo(arr, firstApperance(arr, size, number), lastApperance(arr, size, number)));
    return 0;
}
