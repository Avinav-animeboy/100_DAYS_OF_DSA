/*Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e
*/
#include <stdio.h>
#include <string.h>

char firstRepeatedChar(char *s) {
    int charIndex[26];
    memset(charIndex, -1, sizeof(charIndex));

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        if (charIndex[index] == -1) {
            charIndex[index] = i;
        } else {
            return s[i];
        }
    }

    return -1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    char result = firstRepeatedChar(str);
    if (result != -1) {
        printf("First repeated character: %c\n", result);
    } else {
        printf("No repeated character found.\n");
    }

    return 0;
}