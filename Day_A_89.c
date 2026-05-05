/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).

*/

#include <stdio.h>
#include <stdlib.h>

int isFeasible(int books[], int n, int m, int maxPages) {
    int studentCount = 1;
    int pagesAllocated = 0;

    for (int i = 0; i < n; i++) {
        if (pagesAllocated + books[i] > maxPages) {
            studentCount++;
            pagesAllocated = books[i];
            if (studentCount > m) return 0;
        } else {
            pagesAllocated += books[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int books[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    int low = books[0], high = 0;
    for (int i = 0; i < n; i++) {
        high += books[i];
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isFeasible(books, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", result);
    return 0;
}