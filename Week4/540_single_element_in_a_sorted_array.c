int singleNonDuplicate(int *nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];

    int i = 0;
    while (i < numsSize - 1)
    {
        if (nums[i] != nums[i + 1])
        {
            return nums[i];
        }
        i += 2;
    }
    return nums[numsSize - 1];
}