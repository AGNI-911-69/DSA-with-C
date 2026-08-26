#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *head = NULL, *newNode, *temp, *insertNode;
    int nodeCount, value, position;

    printf("Enter number of nodes: ");
    scanf("%d", &nodeCount);

    for (int index = 0; index < nodeCount; index++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value for node %d: ", index + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position to insert: ");
    scanf("%d", &position);

    insertNode = (struct Node *)malloc(sizeof(struct Node));
    insertNode->data = value;

    if (position == 1)
    {
        insertNode->next = head;
        head = insertNode;
    }
    else
    {
        temp = head;

        for (int index = 1; index < position - 1 && temp != NULL; index++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            free(insertNode);
        }
        else
        {
            insertNode->next = temp->next;
            temp->next = insertNode;
        }
    }
    printf("Linked List after insertion: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}