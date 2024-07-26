int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int left = 0;
    int right = numbersSize - 1;
    int a = numbers[left] + numbers[right];
    while (a != target)
    {
        a = numbers[left] + numbers[right];
        if (a < target)
        {
            left++;
        }
        else if (a == target)
        {
            break;
        }
        else
        {
            right--;
        }
        if (left >= right)
        {
            break;
        }
    }
    int* p = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    p[0] = left;
    p[1] = right;
    return p;
}