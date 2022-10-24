#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *arr = malloc(sizeof(int) * 2);
    *returnSize = 2;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] +  nums[j] == target){
                arr[0] = i;
                arr[1] = j;
            }

        }
    }
    return (arr);
}

int main(void){
    int arr[] = {2,7,11,15};
    int target = 9;
    int len = 0;
    int *sum = twoSum(arr, 4, target, &len);
    for (int i = 0; i < len; i++) {
        printf("%d ", sum[i]);
    }


}