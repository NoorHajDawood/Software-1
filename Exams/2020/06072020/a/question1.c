#include <stdio.h>
int f(char *s)//word length starting from pointer s
{
    int count = 0;
    while(*s && *s++ != ' ')
        ++count;
    return count;
}
int longestWord(char *s)
{
    int max=0,current=0;
    while(*s)
    {
        current = f(s); // get word length
        if(max < current)
            max = current; // store max length
        s += current + 1; // skip word
    }
    return max;
}
int main(int argc, char const *argv[])
{
    char str[] ="     ";
    printf("%d\n", longestWord(str));
    return 0;
}
