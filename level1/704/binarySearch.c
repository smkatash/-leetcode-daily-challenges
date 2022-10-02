#include <stdio.h>

int search(int* nums, int numsSize, int target){
	if (numsSize == 1)
	{
		if (nums[0] == target)
			return (0);
	}
	int	middle = numsSize / 2;
	for (int i = 0; i + middle < numsSize; i++) {
		if (nums[i] == target) 
			return (i);
		if (nums[i + middle] == target)
			return (i + middle);
	}
	return (-1);
}

int	main(void) {
	int nums[] = {-1,0,5};
	int	numsSize = sizeof(nums) / sizeof(int);
	int find = search(nums, numsSize, 5);
	printf("Found: %d\n", find);
	return (0);
}
