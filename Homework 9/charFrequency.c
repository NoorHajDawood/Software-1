#include <stdio.h>

void charFrequency(char *s)
{
    int characters[256] = {0};
    for (int i = 0; s[i]; i++)
    {
        characters[s[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (characters[i])
        {
            printf("%c %d\n", (char)i, characters[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    char str[100];
    gets(str);
    charFrequency(str);
    return 0;
}
