int heightChecker(int *heights, int heightsSize)
{
    int count = 0;
    int exp[heightsSize];
    for (int i = 0; i < heightsSize; i++)
    {
        exp[i] = heights[i];
    }
    for (int i = 0; i < heightsSize - 1; i++)
    {
        for (int j = i + 1; j < heightsSize; j++)
        {
            if (exp[i] > exp[j])
            {
                int temp = exp[i];
                exp[i] = exp[j];
                exp[j] = temp;
            }
        }
    }
    for (int i = 0; i < heightsSize; i++)
    {
        if (exp[i] != heights[i])
        {
            count++;
        }
    }
    return count;
}