#include <stdio.h>

int subArray(int a[], int n1, int b[], int n2)
{
    int index = -1;
    for (int i = 0; i <= (n1-n2) && index == -1; i++)
    {
        index = i;
        for(int j = 0; j < n2 && index != -1; j++)
            if(a[i + j] != b[j])
                index = -1;
    }
    return index;
}

int main(int argc, char const *argv[])
{
    int a[40], n1, b[40], n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
        scanf("%d", &a[i]);
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
        scanf("%d", &b[i]);
    printf("%d", subArray(a, n1, b, n2));
    return 0;
}
