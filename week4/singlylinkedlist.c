#include <stdio.h>
#include <stdlib.h>

typedef struct Node* node;
typedef struct Node {
    int data;
    node next;
} Node;

node head = NULL;

void insertBefore(int val1, int val2) {
    node newNode = (node)malloc(sizeof(Node));
    newNode->data = val1;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf("Head is filled\n");
        return;
    }

    node c = head;
    node prev = NULL;

    while (c != NULL && c->data != val2) {
        prev = c;
        c = c->next;
    }

    if (c == NULL) {
        printf("The specified element is not found in linked list\n");
        free(newNode);
        return;
    }

    if (prev == NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = c;
    }
    printf("Element inserted successfully.\n");
}

void insertAfter(int val1, int val2) {
    node newNode = (node)malloc(sizeof(Node));
    newNode->data = val1;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf("Head is filled\n");
        return;
    }

    node c = head;
    while (c != NULL && c->data != val2) {
        c = c->next;
    }

    if (c == NULL) {
        printf("The specified element is not found in linked list\n");
        free(newNode);
        return;
    }

    newNode->next = c->next;
    c->next = newNode;
    printf("Element inserted successfully.\n");
}

void deletion(int val) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    node c = head;
    node prev = NULL;

    while (c != NULL && c->data != val) {
        prev = c;
        c = c->next;
    }

    if (c == NULL) {
        printf("The specified element is not found in linked list\n");
        return;
    }

    if (prev == NULL) {
        head = c->next;
    } else {
        prev->next = c->next;
    }

    free(c);
    printf("Element deleted successfully.\n");
}

void traversal() {
    node c = head;
    if (c == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Data: \n");
    while (c != NULL) {
        printf("%d ", c->data);
        c = c->next;
    }
    printf("\n");
}

void reverse() {
    node prev = NULL;
    node current = head;
    node nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}

void sort() {
    if (head == NULL || head->next == NULL) return;

    node i, j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void altDel() {
    if (head == NULL || head->next == NULL) return;

    node prev = head;
    node c = head->next;

    while (prev != NULL && c != NULL) {
        prev->next = c->next;
        free(c);
        prev = prev->next;
        if (prev != NULL) {
            c = prev->next;
        } else {
            c = NULL;
        }
    }
}

void addSort(int val) {
    node newNode = (node)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL || head->data >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }

    node c = head;
    while (c->next != NULL && c->next->data < val) {
        c = c->next;
    }

    newNode->next = c->next;
    c->next = newNode;
}

int main() {
    int choice, data, data1;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element before specified element. \n");
        printf("2. Insert an element after specified element. \n");
        printf("3. Delete a specified element from the list.\n");
        printf("4. Traverse the list and display all elements.\n");
        printf("5. Reverse the linked list.\n");
        printf("6. Sort the list in ascending order.\n");
        printf("7. Delete every alternate node in the list.\n");
        printf("8. Insert an element into a sorted linked list while maintaining the sorted order.\n");
        printf("9. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            printf("Enter the element before which to insert new element: ");
            scanf("%d", &data1);
            insertBefore(data, data1);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            printf("Enter the element after which to insert new element: ");
            scanf("%d", &data1);
            insertAfter(data, data1);
            break;
        case 3:
            printf("Enter the element to delete: ");
            scanf("%d", &data);
            deletion(data);
            break;
        case 4:
            traversal();
            break;
        case 5:
            reverse();
            printf("The linked list after reversal:\n");
            traversal();
            break;
        case 6:
            sort();
            printf("The linked list after sorting:\n");
            traversal();
            break;
        case 7:
            altDel();
            printf("The linked list after alternate deletion:\n");
            traversal();
            break;
        case 8:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            addSort(data);
            printf("The linked list after adding in sorted list:\n");
            traversal();
            break;
        case 9:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
