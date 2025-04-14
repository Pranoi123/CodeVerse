int majorityElement(int *nums, int numsSize)
{
    int count = 0;
    int maj = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (count == 0)
        {
            maj = nums[i];
        }
        count += (nums[i] == maj) ? 1 : -1;
    }

    return maj;
}