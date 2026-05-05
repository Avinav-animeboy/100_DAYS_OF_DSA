/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/

#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    float **buckets = (float **)malloc(n * sizeof(float *));
    int *bucketSizes = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
    }

    // Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * n);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets and concatenate
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            // Sort the bucket using insertion sort
            for (int j = 1; j < bucketSizes[i]; j++) {
                float key = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = key;
            }
        }
    }

    // Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.12, 0.53, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");

    return 0;
}