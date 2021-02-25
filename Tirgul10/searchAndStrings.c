#include <stdio.h>
#include <string.h>

void swap(int *x, int *y)
{
    *x += *y;
    *y = *x - *y;
    *x -= *y;
}

int *findNumberinArray(int *arr, int size, int num)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == num)
            return arr + i;
    return NULL;
}

int findAndSwap(int *arr, int size, int x, int y)
{
    int *first = findNumberinArray(arr, size, x);
    int *second = findNumberinArray(arr, size, y);
    if (first && second)
    {
        swap(first, second);
        return 1;
    }
    return 0;
}

int isPalindrom(char *str)
{
    for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
        if (str[i] != str[j])
            return 0;
    return 1;
}

void sortArray(char *arr[], int size)
{
    int tmpSize = size;
    while (tmpSize--)
    {
        for (int i = 0; i < size - 1; i++)
            if (strcmp(arr[i], arr[i + 1]) > -1)
            {
                char *tmpChar = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmpChar;
            }
    }
}

int deleteNumber(int *arr, int *size, int number)
{
    int *p = findNumberinArray(arr, *size, number);
    if (!p)
        return 0;
    while (p < (arr + *size - 1))
    {
        *p = *(p + 1);
        p++;
    }
    return 1;
}
void printIntArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\n", arr[i]);
}

void printStrArray(char *arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);
}
int main(int argc, char const *argv[])
{
    int x = 10;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("quesiton 1: %p\n", findNumberinArray(arr,10,8));
    printf("question 2: %d\n", findAndSwap(arr, 10, 3, 8));
    printIntArray(arr,10);
    printf("question 3: %d\n", isPalindrom("yesey"));
    printf("question 3: %d\n", isPalindrom("yessey"));
    printf("question 3: %d\n", isPalindrom("yesay"));
    int *size = &x;
    printf("question 5: %d\n", x-=deleteNumber(arr, size, 5));
    printIntArray(arr,x);
    printf("question 5: %d\n", x-=deleteNumber(arr, size, 5));
    printIntArray(arr,x);
    char *strArr[] = {"Aaaa", "Aaab", "aaaa", "No", "Yes", "Max"};
    sortArray(strArr, 6);
    printStrArray(strArr, 6);
    return 0;
}
