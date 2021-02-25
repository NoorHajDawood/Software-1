#include <stdio.h>
#include <string.h>

void compress(char *in, char *out)
{
    if (*in == '\0')
    {
        *out = '\0';
        return;
    }
    *out++ = *in;
    char count = '1';
    while (*in == *++in)
        count++;
    if (count > '1')
        *out++ = count;
    compress(in, out);
}

void decompress(char *out, char *dec)
{
    if (*out == '\0')
    {
        *dec = '\0';
        return;
    }
    *dec++ = *out;
    if (out[1] >= '2' && out[1] <= '9')
    {
        for (char i = '1'; i < out[1]; i++)
            *dec++ = *out;
        out++;
    }

    decompress(out + 1, dec);
}

int charSum(char *str)
{
}

int main(int argc, char const *argv[])
{
    char str1[256] = "aabaaaccdd";
    char str2[256] = "";
    char str3[256] = "";
    compress(str1, str2);
    decompress(str2, str3);
    printf("%s\t->\t%s\t->\t%s", str1, str2, str3);
    return 0;
}
