#include <stdio.h>
#include <string.h>

void sortArray(int array[], int n);
int findMaxIndex(int *arr, int i, int j);
void f(int array[], int i, int j);
int FunnyStr(char *str);
void MirrorStr(char *str, char *mirror);
void printArray(int *arr, int n);
int *binary_search(int *left, int *right, int e);
int sumDigits(int n); 
char isDiv3(int n);


char lowercase(char c)
{
    if ('A' <= c && c <= 'Z' )
    {
        return c + 'a'-'A';
    }
    return c;
}

char *stringLowercase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = lowercase(str[i]);
    }
    return str;
}
int main(int argc, char const *argv[])
{

    char str[20] = "1234567890123456789";
    char mirror[20];
    MirrorStr(str, mirror);
    printf("%s\n", mirror);
    printf("%d\n", FunnyStr(str));

    int array[] = {56, 4, -12, 2, 4, -100, 10, 2, 64};
    int n = sizeof(array) / sizeof(int);
    printf("%d\n", n);
    sortArray(array, n);
    printArray(array, n);

    int sortedArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int *binarySearchResult = binary_search(sortedArr, sortedArr + 15, 16);
    if (binarySearchResult == NULL)
        printf("Null\n");
    else
        printf("%d\n", binarySearchResult - sortedArr);

    printf("%d\n", sumDigits(775612));
    printf("%d\n", isDiv3(996486482));

    return 0;
}

void MirrorStr(char *str, char *mirror)
{
    for (int i = 0; i < strlen(str); i++)
        mirror[i] = str[strlen(str) - 1 - i];
    mirror[strlen(str)] = '\0';
}

int FunnyStr(char *str)
{
    char mirror[256]; // ask Amit that he intended for us to assume max length :>
    MirrorStr(str, mirror);
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        int difs, difm;
        difs = str[i] - str[i + 1];
        difm = mirror[i] - mirror[i + 1];
        difs = difs < 0 ? difs * -1 : difs;
        difm = difm < 0 ? difm * -1 : difm;
        if (difs != difm)
            return 0;
    }
    return 1;
}

void f(int array[], int i, int j)
{
    *(array + i) += *(array + j); // i = i + j
    *(array + j) *= -1;           // j = -j
    *(array + j) += *(array + i); // j = -j + i + j = i
    array[i] -= array[j];         // i = i + j - i = j
}

int findMaxIndex(int *arr, int i, int j)
{
    int max = arr[i];
    int maxIndex = i;
    for (int k = i + 1; k <= j; k++)
        if (max < arr[k])
        {
            max = arr[k];
            maxIndex = k;
        }
    return maxIndex;
}

void sortArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int maxIndex = findMaxIndex(array, i, n - 1);
        if (i != maxIndex)
            f(array, i, maxIndex);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int *binary_search(int *left, int *right, int e)
{
    int *m;
    if (left > right)
        return NULL;
    m = left + (right - left) / 2;
    return *m == e ? m : binary_search(e < *m ? left : m + 1,
                                        e > *m ? right : m - 1,
                                            e);
}

int sumDigits(int n)
{
    if(!n)
        return 0;
    return n%10 + sumDigits(n/10);
}

char isDiv3(int n)
{
    if(n < 10)
        return (n == 0) || (n == 3) || (n == 6) || (n == 9);
    return isDiv3(sumDigits(n));
}

