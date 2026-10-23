#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
    int data;
    struct dnode *prev;
    struct dnode *next;
} dnode;

dnode *createNode(int data) {
    dnode *newNode = (dnode *)malloc(sizeof(dnode));

    if (newNode == NULL) {
        printf("\nMemory allocation failed.");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertRear(dnode **head, dnode **tail, int data) {
    dnode *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }
    else {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("\n%d inserted at rear.", data);
}

void deleteRear(dnode **head, dnode **tail) {
    if (*head == NULL) {
        printf("\nList is empty.");
        return;
    }

    dnode *temp = *tail;

    if (*head == *tail) {
        *head = NULL;
        *tail = NULL;
    }
    else {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }

    printf("\n%d deleted from rear.", temp->data);
    free(temp);
}

void insertPosition(dnode **head, dnode **tail,
                    int data, int position) {

    if (position < 1) {
        printf("\nInvalid position.");
        return;
    }

    if (position == 1) {
        dnode *newNode = createNode(data);

        newNode->next = *head;

        if (*head != NULL)
            (*head)->prev = newNode;
        else
            *tail = newNode;

        *head = newNode;

        printf("\n%d inserted at position %d.", data, position);
        return;
    }

    dnode *current = *head;
    int i;

    for (i = 1; i < position - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL) {
        printf("\nInvalid position.");
        return;
    }

    dnode *newNode = createNode(data);

    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != NULL)
        current->next->prev = newNode;
    else
        *tail = newNode;

    current->next = newNode;

    printf("\n%d inserted at position %d.", data, position);
}

void deletePosition(dnode **head, dnode **tail,
                     int position) {

    if (*head == NULL) {
        printf("\nList is empty.");
        return;
    }

    if (position < 1) {
        printf("\nInvalid position.");
        return;
    }

    dnode *current = *head;
    int i;

    for (i = 1; i < position && current != NULL; i++)
        current = current->next;

    if (current == NULL) {
        printf("\nInvalid position.");
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;
    else
        *tail = current->prev;

    printf("\n%d deleted from position %d.",
           current->data, position);

    free(current);
}

void insertAfter(dnode **head, dnode **tail,
                 int searchData, int data) {

    dnode *current = *head;

    while (current != NULL && current->data != searchData)
        current = current->next;

    if (current == NULL) {
        printf("\n%d not found in the list.", searchData);
        return;
    }

    dnode *newNode = createNode(data);

    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != NULL)
        current->next->prev = newNode;
    else
        *tail = newNode;

    current->next = newNode;

    printf("\n%d inserted after %d.", data, searchData);
}

void insertBefore(dnode **head, dnode **tail,
                  int searchData, int data) {

    dnode *current = *head;

    while (current != NULL && current->data != searchData)
        current = current->next;

    if (current == NULL) {
        printf("\n%d not found in the list.", searchData);
        return;
    }

    dnode *newNode = createNode(data);

    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = newNode;
    else
        *head = newNode;

    current->prev = newNode;

    printf("\n%d inserted before %d.", data, searchData);
}

void forwardTraversal(dnode *head) {
    if (head == NULL) {
        printf("\nList is empty.");
        return;
    }

    printf("\nForward: ");

    dnode *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void reverseTraversal(dnode *tail) {
    if (tail == NULL) {
        printf("\nList is empty.");
        return;
    }

    printf("\nReverse: ");

    dnode *current = tail;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
}

void menu() {
    printf("\n\n========== DOUBLY LINKED LIST ==========");
    printf("\n1. Insert at rear");
    printf("\n2. Delete from rear");
    printf("\n3. Insert at given position");
    printf("\n4. Delete from given position");
    printf("\n5. Insert after specific value");
    printf("\n6. Insert before specific value");
    printf("\n7. Forward traversal");
    printf("\n8. Reverse traversal");
    printf("\n9. Exit");
    printf("\n========================================");
}

int main() {
    dnode *head = NULL;
    dnode *tail = NULL;

    int choice;
    int data;
    int position;
    int searchData;

    while (1) {
        menu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);

                insertRear(&head, &tail, data);
                break;

            case 2:
                deleteRear(&head, &tail);
                break;

            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &position);

                insertPosition(&head, &tail, data, position);
                break;

            case 4:
                printf("\nEnter position: ");
                scanf("%d", &position);

                deletePosition(&head, &tail, position);
                break;

            case 5:
                printf("\nEnter existing value: ");
                scanf("%d", &searchData);

                printf("Enter new data: ");
                scanf("%d", &data);

                insertAfter(&head, &tail, searchData, data);
                break;

            case 6:
                printf("\nEnter existing value: ");
                scanf("%d", &searchData);

                printf("Enter new data: ");
                scanf("%d", &data);

                insertBefore(&head, &tail, searchData, data);
                break;

            case 7:
                forwardTraversal(head);
                break;

            case 8:
                reverseTraversal(tail);
                break;

            case 9:
                printf("\nProgram terminated.");
                return 0;

            default:
                printf("\nInvalid choice.");
        }
    }

    return 0;
}
