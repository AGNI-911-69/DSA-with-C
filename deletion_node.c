#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head = NULL, *temp, *newnode, *prev;
    int n, i, ch, pos;

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

    if (ch == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else if (ch == 2)
    {
        temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    else if (ch == 3)
    {
        printf("Enter position: ");
        scanf("%d", &pos);

        temp = head;

        for (i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    printf("\nNew List after deletion: ");
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d -> ", temp->data);
    printf("NULL");

    return 0;
}