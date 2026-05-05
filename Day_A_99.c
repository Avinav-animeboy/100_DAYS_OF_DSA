/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/
#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    int speed;
};

int compare(const void *a, const void *b) {
    return ((struct Car *)b)->position - ((struct Car *)a)->position;
}

int carFleet(int target, struct Car *cars, int n) {
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double time = 0;

    for (int i = 0; i < n; i++) {
        double currTime = (double)(target - cars[i].position) / cars[i].speed;
        if (currTime > time) {
            fleets++;
            time = currTime;
        }
    }

    return fleets;
}

int main() {
    struct Car cars[] = {{0, 2}, {4, 1}, {2, 3}};
    int n = sizeof(cars) / sizeof(cars[0]);
    int target = 5;
    printf("Number of car fleets: %d\n", carFleet(target, cars, n));
    return 0;
}