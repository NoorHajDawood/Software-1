#include <stdio.h>
#include <string.h>

int my_strcmp(char *s, char *t)
{
    int i;
    for (i = 0; s[i] && t[i]; i++)
    {
        if (s[i] < t[i])
            return -1;
        else if (s[i] > t[i])
            return 1;
    }
    if (s[i] && !t[i])
        return 1;
    else if (!s[i] && t[i])
        return -1;
    return 0;
}

int main(int argc, char const *argv[])
{
    char s[256], t[256];
    gets(s);
    gets(t);
    printf("%d", my_strcmp(s, t));
    return 0;
}
