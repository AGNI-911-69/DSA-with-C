#include <stdio.h>
#define MAX 100
typedef struct
{
    int items[MAX];
    int top;
} Stack;
typedef struct
{
    int items[MAX];
    int front;
    int rear;
} Queue;
void initStack(Stack *s)
{
    s->top = -1;
}
void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
void push(Stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
    } else
    {
        s->top++;
        s->items[s->top] = value;
    }
}
int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top--];
}
void displayStack(Stack *s)
{
    int i;
    if (s->top == -1) \
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (i = s->top; i >= 0; i--)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
void enqueue(Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}
int dequeue(Queue *q)
{
    int value;
    if (q->front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    value = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    } else
    {
        q->front++;
    }
    return value;
}
void displayQueue(Queue *q)
{
    int i;
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
int main()
{
    Stack s;
    Queue q;
    int n, value, i;

    initStack(&s);
    initQueue(&q);

    printf("Enter number of elements for stack: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter stack element %d: ", i + 1);
        scanf("%d", &value);
        push(&s, value);
    }
    displayStack(&s);

    printf("Popped element: %d\n", pop(&s));
    displayStack(&s);

    printf("\nEnter number of elements for queue: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter queue element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&q, value);
    }
    displayQueue(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    displayQueue(&q);

    return 0;
}