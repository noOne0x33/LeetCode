#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int index;
} Number;

int compare(const void* a, const void* b) {
    return ((Number*)a)->num - ((Number*)b)->num;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Number numbers[numsSize];
    // Step 1: Map numbers to their original indices.
    for(int i = 0; i < numsSize; i++) {
        numbers[i].num = nums[i];
        numbers[i].index = i;
    }
    // Step 2: Sort the array of numbers.
    qsort(numbers, numsSize, sizeof(Number), compare);
    int left = 0, right = numsSize - 1;

    // Step 3: Use two pointers to find the target sum.
    while(left < right) {
        int sum = numbers[left].num + numbers[right].num;
        // If the sum is equal to the target, return the indices.
        if(sum == target) {
            *returnSize = 2;
            int* result = (int*)malloc(*returnSize * sizeof(int));
            result[0] = numbers[left].index;
            result[1] = numbers[right].index;
            return result;
        } else if(sum < target) {
            left++;
        } else {
            right--;
        }
    }
    // Step 4: If no such indices found, return NULL and set returnSize to 0.
    *returnSize = 0;
    return NULL;
}