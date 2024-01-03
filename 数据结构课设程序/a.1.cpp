#include <stdio.h>
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("请输入数组的大小：");
    scanf("%d", &n);
    int arr[n];
    printf("请输入 %d 个整数：\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    shellSort(arr, n);
    printf("希尔排序后的数组：\n");
    printArray(arr, n);
    return 0;
}

