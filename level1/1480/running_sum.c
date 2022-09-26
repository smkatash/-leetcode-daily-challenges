#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize){
	int *arr_sum;

	if ((numsSize <= 0) || !nums || !returnSize)
		return nums;
	*returnSize = numsSize;
	arr_sum = malloc(sizeof(int) * numsSize);
	arr_sum[0] = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		arr_sum[i] = nums[i] + arr_sum[i - 1];
	}
	return (arr_sum);
}

int main(void) {
	int	nums[] = {1,2,3,4};
	int	size = sizeof(nums) / sizeof(int);
	int	*result;
	int	returnSize = 0;

	result = runningSum(nums, size, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ",result[i]);
	}
	free(result);
	return (0)
}
