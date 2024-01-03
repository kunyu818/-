#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int mid = (total + 1) / 2; // 中位数的位置
    int i = 0, j = 0;
    int current = 0, prev = 0;
    while (i + j <= mid) {
        prev = current;
        if (i < nums1Size && (j >= nums2Size || nums1[i] <= nums2[j])) {
            current = nums1[i];
            i++;
        } else {
            current = nums2[j];
            j++;
        }
    }
    if (total % 2 == 0) {
        return (prev + current) / 2.0;
    } else {
        return current;
    }
}
int main() {
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8, 10};
    int n = sizeof(A) / sizeof(A[0]);
    double median = findMedianSortedArrays(A, n, B, n);
    printf("序列 A 和 B 的中位数为: %.1f\n", median);
    return 0;
}

