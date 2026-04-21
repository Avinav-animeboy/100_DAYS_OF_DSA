/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.
*/
#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(char *s) {
    int charCount[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        charCount[s[i] - 'a']++;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (charCount[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    char result = firstNonRepeatingChar(str);
    printf("First non-repeating character: %c\n", result);

    return 0;
}