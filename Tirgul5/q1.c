#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, positive=0, nigative=0;
    scanf("%d", &n);
    while (n)
    {
        if(n>0)
            positive++;
        else
            nigative++;
        scanf("%d", &n);
    }
    if((positive+nigative))
        printf("%% of positives is: %f%%\n%% of nigatives is: %f%%", (100*(float)positive/(positive+nigative)), (100*(float)nigative/(positive+nigative)));
    else
        printf("didnt get any numbers");
    return 0;
}