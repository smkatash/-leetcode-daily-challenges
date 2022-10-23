#include <stdio.h>
#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int *arr = malloc(sizeof(int)*(2));
    int hash[10000] = {0};
    for(int i = 0; i < numsSize; i++)
    {
        hash[nums[i] - 1]++;
    }
    for(int i = 0; i < numsSize; i++)
    {
        if (hash[i] == 2)
            arr[0] = i + 1;
        if (hash[i] == 0)
            arr[1] = i + 1;
    }
    *returnSize = 2;
    return (arr);
}


int main(void)
{
    int nums[] = {3, 2, 2};
    int len = 0;
    int *arr = findErrorNums(nums, 3, &len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return (0);
}