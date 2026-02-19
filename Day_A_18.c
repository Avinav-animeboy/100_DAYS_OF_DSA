/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100], temp[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int k;
    scanf("%d", &k);

    k = k % n;

    for (int i = 0; i < k; i++)
        temp[i] = arr[n - k + i];

    
    for (int i = n - 1; i >= k; i--)
        arr[i] = arr[i - k];
    
    for (int i = 0; i < k; i++)
        arr[i] = temp[i];

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}
