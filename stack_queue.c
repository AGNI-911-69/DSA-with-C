#include <stdio.h>
#define MAX 100
int main()
{
    int stack[MAX], queue[MAX];
    int top = -1, front = -1, rear = -1;
    int n, i, value;
    // Stack //
    printf("Enter number of elements for stack: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter stack element %d: ", i + 1);
        scanf("%d", &value);

        if (top == MAX - 1)
            printf("Stack Overflow\n");
        else
            stack[++top] = value;
    }
    printf("\nStack elements: ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    if (top == -1)
        printf("\nStack Underflow\n");
    else
        printf("\nPopped element from stack: %d\n", stack[top--]);
    // Queue //
    printf("\nEnter number of elements for queue: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter queue element %d: ", i + 1);
        scanf("%d", &value);

        if (rear == MAX - 1)
            printf("Queue Overflow\n");
        else
        {
            if (front == -1)
                front = 0;
            queue[++rear] = value;
        }
    }
    printf("\nQueue elements: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    if (front == -1 || front > rear)
        printf("\nQueue Underflow\n");
    else
        printf("\nDequeued element from queue: %d\n", queue[front++]);

    return 0;
}
