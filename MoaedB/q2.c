#include <stdio.h>

int ab(char *s)
{
    if(s[0] == '\0' || s[1] == '\0')
        return 0; 
    int counter = 0, counterA, counterB;
    for(int i = 0; s[i+1] != '\0'; i++)
    {
        for(int j = i+1; s[j] != '\0'; j++)
        {
            counterA = 0;
            counterB = 0;
            for(int k = i; k<=j; k++)
            {
                if(s[k] == 'a' || s[k] == 'A')
                    counterA++;
                if(s[k] == 'b' || s[k] == 'B')
                    counterB++;
            }
            counter += ((counterA == counterB && counterA != 0) ? 1 : 0);
        }
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    char *str = "AxAbbTTbAsbbaWaA12abBaTb";
    printf("%d\n", ab(str));
    return 0;
}
