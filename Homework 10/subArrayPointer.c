#include <stdio.h>

int *subArray(int *a, int n1, int *b, int n2)
{
    int *index = NULL;
    for (int i = 0; i <= (n1-n2) && index == NULL; i++)
    {
        index = a+i;
        for(int j = 0; j < n2 && index; j++)
            if(a[i + j] != b[j])
                index = NULL;
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
    //printf("%p", subArray(a, n1, b, n2));
    int *p = subArray(a, n1, b, n2);
    if(p)
        printf("%d", (p-a));
    else
        printf("-1");
    return 0;
}
