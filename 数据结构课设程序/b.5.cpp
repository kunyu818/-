#include <stdio.h>
#include <stdlib.h>
int countInversions(int arr[], int n) {
    int inversions = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}
int main() {
    int n;
    printf("���������еĴ�С��");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("������1-%d��������У�", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int inversions = countInversions(arr, n);
    printf("���ٲ�����%d\n", inversions);
    free(arr);
    return 0;
}

