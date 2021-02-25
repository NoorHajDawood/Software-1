#include <stdio.h>

char isPalindromeInt(int a[], int n);

int main(int argc, char const *argv[])
{
    int arr[20] = {0}, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    printf("%s", isPalindromeInt(arr, n) ? "Palindrome" : "Not Palindrome");
    return 0;
}

char isPalindromeInt(int a[], int n)
{
    if(n < 2)
        return 1;
    return (a[0] == a[n-1]) ? isPalindromeInt(a+1, n-2) : 0;
}