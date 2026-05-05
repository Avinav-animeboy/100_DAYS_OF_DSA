/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/

#include <stdio.h>
#include <stdlib.h>

struct Meeting {
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    return ((struct Meeting *)a)->start - ((struct Meeting *)b)->start;
}

int minMeetingRooms(struct Meeting *meetings, int n) {
    qsort(meetings, n, sizeof(struct Meeting), compare);

    int *endTimes = (int *)malloc(n * sizeof(int));
    int rooms = 0;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < rooms; j++) {
            if (endTimes[j] <= meetings[i].start) {
                endTimes[j] = meetings[i].end;
                break;
            }
        }
        if (j == rooms) {
            endTimes[rooms++] = meetings[i].end;
        }
    }

    free(endTimes);
    return rooms;
}

int main() {
    struct Meeting meetings[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(meetings) / sizeof(meetings[0]);
    printf("Minimum number of meeting rooms required: %d\n", minMeetingRooms(meetings, n));
    return 0;
}