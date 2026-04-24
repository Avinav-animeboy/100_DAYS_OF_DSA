/*
Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.
*/
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_NAME_LENGTH 100

int main() {
    int n;
    scanf("%d", &n);

    char candidates[MAX_CANDIDATES][MAX_NAME_LENGTH];
    int votes[MAX_CANDIDATES] = {0};
    int candidate_count = 0;

    for (int i = 0; i < n; i++) {
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        // Check if the candidate already exists
        int found = 0;
        for (int j = 0; j < candidate_count; j++) {
            if (strcmp(candidates[j], name) == 0) {
                votes[j]++;
                found = 1;
                break;
            }
        }

        // If the candidate is new, add them to the list
        if (!found) {
            strcpy(candidates[candidate_count], name);
            votes[candidate_count]++;
            candidate_count++;
        }
    }

    // Find the candidate with the maximum votes
    int max_votes = 0;
    char winner[MAX_NAME_LENGTH];
    for (int i = 0; i < candidate_count; i++) {
        if (votes[i] > max_votes || (votes[i] == max_votes && strcmp(candidates[i], winner) < 0)) {
            max_votes = votes[i];
            strcpy(winner, candidates[i]);
        }
    }

    printf("%s %d\n", winner, max_votes);
    return 0;
}
