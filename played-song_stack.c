#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char song[100];
    struct Node *next;
};
struct Node *top = NULL;

void playSong() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter song name: ");
    scanf(" %[^\n]", newNode->song);

    newNode->next = top;
    top = newNode;

    printf("\"%s\" added to recently played list.\n", newNode->song);
}
void removeRecentSong() {
    if (top == NULL) {
        printf("No recently played songs available.\n");
        return;
    }
    struct Node *temp = top;
    printf("Removed most recently played song: %s\n", top->song);

    top = top->next;
    free(temp);
}
void displaySongs() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Recently played list is empty.\n");
        return;
    }
    printf("\nRecently Played Songs:\n");
    int i = 1;
    while (temp != NULL) {
        printf("%d. %s\n", i++, temp->song);
        temp = temp->next;
    }
}
int main() {
    int choice;
    do {
        printf("\n--- Music Player Menu ---\n");
        printf("\n1. Play a song\n");
        printf("2. Remove most recent song\n");
        printf("3. Display recently played songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playSong();
                break;
            case 2:
                removeRecentSong();
                break;
            case 3:
                displaySongs();
                break;
            case 4:
                printf("Exiting music player.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}