#include <stdio.h>

void DisplayArray2D(char arr[][7])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }
}

void RotateArray2D(char arrRotated[][7], char arrOriginal[][7])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
            arrRotated[j][6 - i] = arrOriginal[i][j];
    }
}

int main(int argc, char const *argv[])
{
    char arr[7][7] = {
        {'*', ' ', ' ', ' ', ' ', ' ', ' '},
        {'*', '*', ' ', ' ', ' ', ' ', ' '},
        {'*', '*', '*', ' ', ' ', ' ', ' '},
        {'*', '*', '*', '*', '*', '*', '*'},
        {'*', '*', '*', ' ', ' ', ' ', ' '},
        {'*', '*', ' ', ' ', ' ', ' ', ' '},
        {'*', ' ', ' ', ' ', ' ', ' ', ' '},
    };
    char arrRotated[7][7];
    DisplayArray2D(arr);
    RotateArray2D(arrRotated, arr);
    DisplayArray2D(arrRotated);
    RotateArray2D(arr, arrRotated);
    DisplayArray2D(arr);
    return 0;
}
