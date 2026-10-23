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
}

void display(dnode *head) {
    dnode *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void concatenate(dnode **head1, dnode **tail1,
                 dnode *head2, dnode *tail2) {

    if (*head1 == NULL) {
        *head1 = head2;
        *tail1 = tail2;
        return;
    }

    if (head2 == NULL)
        return;

    (*tail1)->next = head2;
    head2->prev = *tail1;

    *tail1 = tail2;
}

int main() {

    dnode *head1 = NULL;
    dnode *tail1 = NULL;

    dnode *head2 = NULL;
    dnode *tail2 = NULL;

    int n1, n2, data, i;

    printf("Enter number of nodes in X1: ");
    scanf("%d", &n1);

    printf("Enter elements of X1:\n");

    for (i = 1; i <= n1; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);

        insertRear(&head1, &tail1, data);
    }

    printf("\nEnter number of nodes in X2: ");
    scanf("%d", &n2);

    printf("Enter elements of X2:\n");

    for (i = 1; i <= n2; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);

        insertRear(&head2, &tail2, data);
    }

    printf("\nX1 before concatenation: ");
    display(head1);

    printf("X2 before concatenation: ");
    display(head2);

    concatenate(&head1, &tail1, head2, tail2);

    printf("\nX1 after concatenation: ");
    display(head1);

    return 0;
}
