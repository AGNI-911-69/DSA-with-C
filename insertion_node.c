#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head = NULL, *temp, *newnode;
    int n, i, ch, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    printf("\nNormal List: ");
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d -> ", temp->data);
    printf("NULL\n");

    printf("\n1. Beginning  2. End  3. Position\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newnode = malloc(sizeof(struct node));
    newnode->data = value;

    if (ch == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else if (ch == 2)
    {
        newnode->next = NULL;
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
    else if (ch == 3)
    {
        printf("Enter position: ");
        scanf("%d", &pos);

        temp = head;

        for (i = 1; i < pos - 1; i++)
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("\nNew List after insertion: ");
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d -> ", temp->data);
    printf("NULL");

    return 0;
}