/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct node *temp;
    int val;

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int evaluatePostfix(char exp[])
{
    int i = 0;
    int a, b, result;

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            b = pop();
            a = pop();

            if(exp[i] == '+')
                result = a + b;
            else if(exp[i] == '-')
                result = a - b;
            else if(exp[i] == '*')
                result = a * b;
            else if(exp[i] == '/')
                result = a / b;

            push(result);
        }

        i++;
    }

    return pop();
}

int main()
{
    char exp[] = "231*+9-";

    int result = evaluatePostfix(exp);

    printf("Result = %d", result);

    return 0;
}