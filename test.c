#include <stdio.h>

/* intput two int numbers and print the result of dividing them once as int/int and once as float/int */

/* intput three numbers and print the maximum between them:
    for example if input is 9 -15 12, then the output should be "12"
    try with trenary expression */

/* input n numbers and print their average */

/* input numbers till -1 and print their sum */

/* input a character and a number, and print a triangle of that character with that many rows */

/* basic calculator */

/* fibonacci */

/* power */

/* factorial */

/* square-root */

int main(int argc, char const *argv[])
{
    int x = 0, y = 0 , z = 0, max =-56;


    do
    {
        scanf("%d %d %d", &x, &y, &z);

        if (x > y)
        {
            if (x > z)
                max = x;
            else
                max = z;
        }
        else
        {
            if (y > z)
                max = y;
            else
                max = z;
        }

        printf("the maximum value is : %d\n", max);
        
    } while (max > 0);
    

    while (max > 0)
    {
        scanf("%d %d %d", &x, &y, &z);

        if (x > y)
        {
            if (x > z)
                max = x;
            else
                max = z;
        }
        else
        {
            if (y > z)
                max = y;
            else
                max = z;
        }

        printf("the maximum value is : %d\n", max);
    }
    //
    //
    //
}
