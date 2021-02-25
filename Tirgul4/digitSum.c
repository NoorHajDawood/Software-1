#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num, sum=0;
    scanf("%d", &num);
    while(num){
        sum += (num%10);
        num/=10;
    }
    printf("%d\n", sum);
    return 0;
}
