/*
Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].
*/

#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
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

    return inv_count;
}

int merge_sort(int arr[], int temp[], int left, int right) {
    int inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += merge_sort(arr, temp, left, mid);
        inv_count += merge_sort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int arr[] = {2, 3, 8, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *temp = (int *)malloc(n * sizeof(int));
    int inv_count = merge_sort(arr, temp, 0, n - 1);
    free(temp);
    printf("Number of inversions are: %d\n", inv_count);
    return 0;
}