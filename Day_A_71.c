/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.
*/
#include <stdio.h>
#include <string.h>

#define MAX 100
int hashTable[MAX];
int size = 0;

int hash(int key) {
    return key % MAX;
}

void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[index] != 0 && i < MAX) {
        index = (index + i * i) % MAX;
        i++;
    }

    if (i < MAX) {
        hashTable[index] = key;
        size++;
    }
}

int search(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[index] != 0 && i < MAX) {
        if (hashTable[index] == key) {
            return 1;  // FOUND
        }
        index = (index + i * i) % MAX;
        i++;
    }

    return 0;  // NOT FOUND
}

int main() {
    int n, key;
    char operation[10];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            if (search(key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    return 0;
}
