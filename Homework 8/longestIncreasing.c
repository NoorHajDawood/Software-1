#include <stdio.h>

int longestIncreasingLength(int arr[], int n)
{
    int counter = 1, max = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] < arr[i+1])
            counter++;
        else
        {
            if (max < counter)
                max = counter;
            counter = 1;
        }
    }
    return max < counter ? counter : max;
}

int main(int argc, char const *argv[])
{
    int arr[20], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d", longestIncreasingLength(arr, n));
    return 0;
}
