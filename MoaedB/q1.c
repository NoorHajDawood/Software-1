#include <stdio.h>
struct dbl
{
    int x, y;
};
int main(int argc, char const *argv[])
{
    for (int i = -10; i <= 10; i++)
    {
        struct dbl dblValues = {i};
        struct dbl *p = &dblValues;
        p->y = p->x;
        printf("%d\n", p->x-- && ++(p->y) ? p->y - p->x-- : --(p->y) - p->x++);
    }
    return 0;
}
