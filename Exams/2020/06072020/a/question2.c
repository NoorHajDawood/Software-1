int CountDup(char *s)
{
    int count = 0;
    while(*s && *(s+1)!='\0')
        count += (*s++ == *s);
        return count;
}