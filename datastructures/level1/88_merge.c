#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
	int	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int	temp = 0;
	int	j;

	for (int i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (nums1[i] > nums2[j])
				swap(&nums1[i], &nums2[j]);
		}
	}
	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (nums2[i] > nums2[i + 1])
				swap(&nums2[i], &nums2[i + 1]);
		}
	}
	j = 0;
	for (int i = m; i < nums1Size; i++) {
		nums1[i] = nums2[j++];
	}
}

// int main(void)
// {
// 	int	nums1[] = {4,5,6,0,0,0};
// 	int	m = 3;
// 	int	nums2[] = {1,2,3};
// 	int	n = 3;
// 	int	nums1Size = sizeof(nums1) / sizeof(int);
// 	int	nums2Size = sizeof(nums2) / sizeof(int);
// 	merge(nums1, nums1Size, m, nums2, nums2Size, n);
// 	for (int i = 0; i < nums1Size; i++)
// 	{
// 		printf("%d ", nums1[i]);
// 	}
// 	return (0);
// }