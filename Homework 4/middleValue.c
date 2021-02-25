#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    // b middle
    if ((a>b && b>c)||(c>b&&b>a))
        printf("%d", b);
    // c middle
    else if ((a>c&&c>b)||(b>c&&c>a))   
        printf("%d", c);
    // a middle
    else
        printf("%d", a);
    return 0;
}
