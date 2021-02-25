#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    char op;
    scanf("%d %c %d", &a, &op, &b);
    switch (op)
    {
    case '+':
        printf("%d", a + b);
        break;
    case '-':
        printf("%d", a - b);
        break;
    case '*':
        printf("%d", a * b);
        break;
    case '/':
        if (!b)
            printf("ERROR");
        else
            printf("%d", a / b);
        break;
    }
    return 0;
}
