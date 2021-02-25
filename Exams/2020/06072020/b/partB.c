#include <stdio.h>
int pascalValue(int line, int col)
{
    if (col > line)
        return 0;
    if (col == 1 || col == line)
        return 1;
    else
        return pascalValue(line - 1, col - 1) + pascalValue(line - 1, col);
}
int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            if(j <= i)
                printf("%d ", pascalValue(i,j));
        printf("\n");
    }
    return 0;
}