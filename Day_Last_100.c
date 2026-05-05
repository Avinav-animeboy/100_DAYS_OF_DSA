/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int temp[], int left, int mid, int right, int *count) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] > arr[j]) {
            temp[k++] = arr[i++];
            (*count) += (right - j + 1);
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void merge_sort(int arr[], int temp[], int left, int right, int *count) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(arr, temp, left, mid, count);
        merge_sort(arr, temp, mid + 1, right, count);
        merge(arr, temp, left, mid, right, count);
    }
}

int main() {
    int arr[] = {5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *temp = (int *)malloc(n * sizeof(int));
    int count = 0;

    merge_sort(arr, temp, 0, n - 1, &count);
    free(temp);

    printf("Number of smaller elements on right side: %d\n", count);
    return 0;
}