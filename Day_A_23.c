/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a linked list
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int value;
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        
        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Function to merge two sorted lists
struct node* mergeLists(struct node* head1, struct node* head2) {
    
    struct node dummy;   // temporary node
    struct node* tail = &dummy;
    dummy.next = NULL;
    
    while(head1 != NULL && head2 != NULL) {
        if(head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    
    // Attach remaining nodes
    if(head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;
        
    return dummy.next;
}

// Function to print list
void printList(struct node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;
    
    scanf("%d", &n);
    struct node* head1 = createList(n);
    
    scanf("%d", &m);
    struct node* head2 = createList(m);
    
    struct node* merged = mergeLists(head1, head2);
    
    printList(merged);
    return 0;
}
