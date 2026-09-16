#include <stdio.h>
int main() {
    int queue[20] = {64, 32, 46, 21, 17, 53};
    int n = 6, i, pos1, pos2, temp, num, insertPos;

    printf("Initial queue: ");
    for (i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }
    printf("\nEnter two positions to delete (1 to %d): ", n);
    scanf("%d %d", &pos1, &pos2);

    if (pos1 < 1 || pos1 > n || pos2 < 1 || pos2 > n || pos1 == pos2) {
        printf("Invalid positions.\n");
        return 0;
    }
    if (pos1 < pos2) {
        temp = pos1;
        pos1 = pos2;
        pos2 = temp;
    }
    for (i = pos1 - 1; i < n - 1; i++) {
        queue[i] = queue[i + 1];
    }
    n--;
    for (i = pos2 - 1; i < n - 1; i++) {
        queue[i] = queue[i + 1];
    }
    n--;
    printf("Queue after deletion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }
    printf("\nEnter number to insert: ");
    scanf("%d", &num);

    printf("Enter insertion position (1 to %d): ", n + 1);
    scanf("%d", &insertPos);

    if (insertPos < 1 || insertPos > n + 1) {
        printf("Invalid position.\n");
        return 0;
    }
    for (i = n; i >= insertPos; i--) {
        queue[i] = queue[i - 1];
    }
    queue[insertPos - 1] = num;
    n++;

    printf("Final queue: ");
    for (i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }
    return 0;
}    