#include <stdio.h>

int main(int argc, char const *argv[])
{
    int height, width;
    printf("Rectangle's height: ");
    scanf("%d", &height);
    printf("Rectangle's width: ");
    scanf("%d", &width);
    printf("Rectangle's area: %d\nRectangle's circumference: %d", height * width, 2 * (height + width));
    return 0;
}
