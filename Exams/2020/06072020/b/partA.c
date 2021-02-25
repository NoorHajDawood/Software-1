int pascalValue(int line, int col)
{
    if (col > line)
        return 0;
    if (col == 1 || col == line)
        return 1;
    else
        return pascalValue(line - 1, col - 1) + pascalValue(line - 1, col);
}