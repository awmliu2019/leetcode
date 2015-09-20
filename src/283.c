#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

/* Bubble sort, O(n*n) */
void moveZeroes0(int* nums, int numsSize) {
    int i, j;
    for (i = numsSize - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (nums[j] == 0 && nums[j + 1] != 0) {
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }
}

/* Divide and conquer, O(nlogn) */
void moveZeroes(int* nums, int numsSize) {
    if (numsSize <= 1 ) return;
    if (numsSize == 2) {
        if (nums[0] == 0 && nums[1] != 0) {
            swap(&nums[0], &nums[1]);
        }
        return;
    }

    int mid = numsSize / 2;

    moveZeroes(nums, mid);
    moveZeroes(nums + mid, numsSize - mid);

    int left = 0, right = numsSize - 1;
    while (nums[left] != 0) left++;
    while (nums[right] == 0) right--;

    if (right <= left) return;

    int i;
    for (i = left; i <= left + (mid - 1 - left) / 2 ; i++) {
        swap(&nums[i], &nums[mid - 1 - i + left]);
    }

    for (i = mid; i <= mid + (right - mid - 1) / 2; i++) {
        swap(&nums[i], &nums[right  - i + mid]);
    }

    for (i = left; i <= left + (right - left) / 2; i++) {
        swap(&nums[i], &nums[right - i + left]);
    }
}

int main() {
    int nums[] = { 0, 1, 0, 3, 12 };
    int size = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, size);

    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
