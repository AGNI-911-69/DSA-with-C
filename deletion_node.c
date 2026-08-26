#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *head = NULL, *newNode, *temp, *deleteNode;
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
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (head == NULL)
    {
        printf("Linked list is empty.\n");
    }
    else if (position == 1)
    {
        deleteNode = head;
        head = head->next;
        free(deleteNode);
    }
    else
    {
        temp = head;

        for (int index = 1; index < position - 1 && temp != NULL; index++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            printf("Invalid position.\n");
        }
        else
        {
            deleteNode = temp->next;
            temp->next = deleteNode->next;
            free(deleteNode);
        }
    }
    printf("Linked List after deletion: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}