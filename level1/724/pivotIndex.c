#include <stdio.h>
#include <stdlib.h>

int pivotIndex(int* nums, int numsSize){
	int mid_index;
	int	index = 0;
	int sum_left = 0;
	int sum_right = 0;
	int	count = 0;

	if (!nums || numsSize <= 0)
		return (0);
	mid_index = numsSize / 2;
	while (mid_index >= 0)
	{
		sum_left = 0;
		sum_right = 0;
		for (int i = 0; i < mid_index; i++)
			sum_left += nums[i];
		for (int i = mid_index + 1; i < numsSize; i++)
			sum_right += nums[i];
		if (sum_left == sum_right)
		{
			index = mid_index;
			count++;
		}
		mid_index--;
	}
	if (count > 0)
		return (index);
	while (mid_index < numsSize)
	{
		sum_left = 0;
		sum_right = 0;
		for (int i = 0; i < mid_index; i++)
			sum_left += nums[i];
		for (int i = mid_index + 1; i < numsSize; i++)
			sum_right += nums[i];
		if (sum_left == sum_right)
		{
			index = mid_index;
			count++;
			break ;
		}
		mid_index++;
	}
	if (index == 0 && count == 0)
		return(-1);
	else
		return (index);
}

int	main(void) {
	int	nums[] = {-1,-1,-1,-1,-1,0};
	int	nums2[] = {1,7,3,6,5,6};
	int	nums3[] = {1,2,3};
	int	nums4[] = {-1,-1,-1,-1,0,1};
	int	nums5[] = {2,1,-1};
	int	nums6[] = {-1,-1,0,0,-1,-1};
	int	nums7[] = {-1,-1,1,1,0,0};
	int	size = sizeof(nums) / sizeof(int);
	int	size2 = sizeof(nums2) / sizeof(int);
	int	size3 = sizeof(nums3) / sizeof(int);
	int	size4 = sizeof(nums4) / sizeof(int);
	int	size5 = sizeof(nums5) / sizeof(int);
	int	size6 = sizeof(nums6) / sizeof(int);
	int	size7 = sizeof(nums7) / sizeof(int);
	int	result;
	int	result2;
	int	result3;
	int	result4;
	int	result5;
	int	result6;
	int	result7;

	result = pivotIndex(nums, size);
	result2 = pivotIndex(nums2, size2);
	result3 = pivotIndex(nums3, size3);
	result4 = pivotIndex(nums4, size4);
	result5 = pivotIndex(nums5, size5);
	result6 = pivotIndex(nums6, size6);
	result7 = pivotIndex(nums7, size7);
	printf("{-1,-1,-1,-1,-1,0} Pivot Index 2, mine is  %d\n",result);
	printf("{1,7,3,6,5,6} : Pivot Index 3, mine is %d\n",result2);
	printf("{1,2,3} : Pivot Index -1, mine is %d\n",result3);
	printf("{-1,-1,-1,-1,0,1} : Pivot Index 1, mine is %d\n", result4);
	printf("{2,1,-1}; : Pivot Index 0, mine is %d\n", result5);
	printf("{-1,-1,0,0,-1,-1}; : Pivot Index 2, mine is %d\n", result6);
	printf("{-1,-1,1,1,0,0}; : Pivot Index 4, mine is %d\n", result7);
	return (0);
}