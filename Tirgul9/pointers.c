#include <stdio.h>
#include <string.h>

void swap(int *x, int *y)
{
    *x += *y;
    *y = *x - *y;
    *x -= *y;
}

int strLength(char *str)
{
    char *tmp = str;
    while (*tmp)
        tmp++;
    return tmp - str;
}

char *strCat3(char *c, char *a, char *b)
{
    char *tmp = c;
    while(*a)
        *tmp++ = *a++;
    while(*b)
        *tmp++ = *b++;
    *tmp = '\0';
    return c;
}

int main(int argc, char const *argv[])
{
    int x = 15, y = 30;
    swap(&x, &y);
    printf("x = %d  y = %d\n", x, y);

    char a[256] = "this is A", b[256] = "this is B", c[256] = "";
    gets(a);
    printf("%d\n", strLength(a));
    printf("%s", strCat3(c, a, b));
    return 0;
}
