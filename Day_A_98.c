/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.
*/

#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}

void mergeIntervals(struct Interval *intervals, int n) {
    if (n <= 0) return;

    qsort(intervals, n, sizeof(struct Interval), compare);

    struct Interval *merged = (struct Interval *)malloc(n * sizeof(struct Interval));
    int j = 0;

    merged[j] = intervals[0];

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= merged[j].end) {
            if (intervals[i].end > merged[j].end) {
                merged[j].end = intervals[i].end;
            }
        } else {
            j++;
            merged[j] = intervals[i];
        }
    }

    for (int i = 0; i <= j; i++) {
        printf("[%d, %d] ", merged[i].start, merged[i].end);
    }
    printf("\n");

    free(merged);
}

int main() {
    struct Interval intervals[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    printf("Merged intervals: ");
    mergeIntervals(intervals, n);
    return 0;
}