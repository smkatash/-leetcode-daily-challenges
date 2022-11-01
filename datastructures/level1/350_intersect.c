#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *arr;
    int k = 0;

    if (nums1Size > nums2Size)
        arr = malloc(sizeof(int) * nums1Size);
    else
        arr = malloc(sizeof(int) * nums2Size);
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j] && nums1[i] >= 0)
            {
                arr[k++] = nums1[i];
                nums1[i] = -1;
                nums2[j] = -1;
            }
        }
    }
    *returnSize = k;
    return (arr);
}

int main(void)
{
    int nums1[] = {1,2,2,1};
    int nums2[] = {1,2};
    int size1 = sizeof(nums1) / sizeof(int);
    int size2 = sizeof(nums2) / sizeof(int);
    int len = 0;
    int *new = intersect(nums1, size1, nums2, size2, &len);
    for (int i = 0; i < len; i++) {
        printf("%d ", new[i]);
    }
    return (0);
}