#include <stdio.h>

int main(int argc, char const *argv[])
{
    int HH, MM, SS, hh, mm, ss, FH, FM, FS;

    // time input
    scanf("%d%d%d", &HH, &MM, &SS);
    scanf("%d%d%d", &hh, &mm, &ss);

    // convert time to seconds and add them
    int inSeconds1st, inSeconds2nd, totalSeconds;
    inSeconds1st = SS + 60*MM + 60*60*HH;
    inSeconds2nd = ss + 60*mm + 60*60*hh;
    totalSeconds = inSeconds1st + inSeconds2nd;
    
    // convert total from seconds to time
    FH = totalSeconds/(60*60);
    totalSeconds -= FH*60*60;
    FM = totalSeconds/60;
    totalSeconds -= FM*60;
    FS = totalSeconds;
    // make sure hours do 24 hour cycle
    FH %= 24;

    printf("%d %d %d", FH, FM, FS);
    return 0;
}
