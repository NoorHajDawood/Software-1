#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num, root=0;
    scanf("%d", &num);
    while((root*root) < num){
        root++;
    }
    if ((root*root) == num)
    {
        printf("%d sqaure root is %d\n", num, root);
    }else{
        printf("%d doesn't have an integere square root\n", num);
    }
    
    return 0;
}
