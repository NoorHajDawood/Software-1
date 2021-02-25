#include <stdio.h>

int sumUnique(int *arr, int n);
int isUnique(int *arr, int n, int l);
void f(int array[], int i, int j);
int slalum(int array[], int n);
int CountChar(char *s, char c);
int sumUnique_r(unsigned int *arr, int n);
int exists(int val, int arr[], int n);

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
    int arr[] = {1, -3, 1, 22, 4, -8, 4};
    printf("%d\n", sumUnique(arr, 7));

    int slal[] = {2, 4, 3, 4, 7, 2, 1, 6, 5};
    int tmp = slalum(slal, 9);
    printArray(slal, 9);
    printf("%d\n", tmp);

    int arr5[] = {1, -3, 1, 22, 4, -8, 4};
    printf("%d\n", sumUnique_r(arr5, 7));
    printArray(arr5, 7);

    return 0;
}

int isUnique(int *arr, int n, int l)
{
    for (int sum = 0, i = 0; i < n; ++i)
        if (arr[i] == l && ++sum == 2)
            return 0;
    return 1;
}

int sumUnique(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += isUnique(arr, n, arr[i]) ? arr[i] : 0;
    }
    return sum;
}

void f(int array[], int i, int j) // cicle right
{
    int *p;
    for (p = array + i + 1; p <= array + j; ++p)
    {
        int t = array[i];
        array[i] = *p;
        *p = t;
    }
}

int slalum(int array[], int n)
{
    for (int i = 0, j; i < n; i++)
    {
        if (array[i] % 2 != i % 2)
        {
            for (j = i + 1; j < n; j++)
            {
                if (array[j] % 2 == i % 2)
                {
                    f(array, i, j);
                    break;
                }
            }
            if (j == n)
            {
                return 0;
            }
        }
    }
    return 1;
}
int CountChar(char *s, char c)
{
    int count = 0;
    while (*s)
        count += (*s++ == c ? 1 : 0);
    return count;
}

/* this changes the array
int sumUnique_r(unsigned int *arr, int n)
{
    if (n == 0)
        return 0;
    return (exsits(arr[0], arr + 1, n - 1) ? arr[0] = 0 : arr[0]) + sumUnique_r(arr + 1, n - 1);
}
char exsits(int val, int arr[], int n)
{
    int flag = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] == val)
        {
            flag = 1;
            arr[i] = 0;
        }
    return flag;
}
*/

int exists(int val, int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] == val)
            ++count;
    return count;
}
int sumUnique_r(unsigned int *arr, int n)
{
    if (n == 0)
        return 0;
    int count = exists(arr[0], arr + 1, n - 1);
    return sumUnique_r(arr + 1, n - 1) + (count ? (count == 1 ? -arr[0] : 0) : arr[0]);
}