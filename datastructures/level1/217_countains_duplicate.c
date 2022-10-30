#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int 	_compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize){
	if (numsSize < 2)
		return (false);
    qsort(nums, numsSize, sizeof(int), _compare);
    for (int i = 0; i < numsSize-1; i++)
        if (nums[i] == nums[i + 1])
            return true;
    return false;
}

int	main(void)
{
	int arr[] = {1,5,-2,-4,0};
	int size = sizeof(arr) / sizeof(int);
	int	result = containsDuplicate(arr, size);
	printf("%d\n", result);
	return (0);
}