#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* llink;
    struct Node* rlink;
} Node;

Node* insert(Node* root, int val) {
    if (root == NULL) {
        Node* nn = (Node*)malloc(sizeof(Node));
        if (nn == NULL) {
            printf("Memory allocation failed!\n");
            return NULL;
        }
        nn->val = val;
        nn->llink = NULL;
        nn->rlink = NULL;
        return nn;
    }

    if (val < root->val) {
        root->llink = insert(root->llink, val);
    } else if (val > root->val) {
        root->rlink = insert(root->rlink, val);
    }
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->llink);
        printf("%d ", root->val);
        inOrder(root->rlink);
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preOrder(root->llink);
        preOrder(root->rlink);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->llink);
        postOrder(root->rlink);
        printf("%d ", root->val);
    }
}

Node* searchBST(Node* root, int key) {
    if (root == NULL || root->val == key)
        return root;

    if (key < root->val)
        return searchBST(root->llink, key);

    return searchBST(root->rlink, key);
}

Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->llink != NULL) {
        root = root->llink;
    }
    return root;
}

Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->rlink != NULL) {
        root = root->rlink;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->val) {
        root->llink = deleteNode(root->llink, key);
    } else if (key > root->val) {
        root->rlink = deleteNode(root->rlink, key);
    } else {
        if (root->llink == NULL) {
            Node* temp = root->rlink;
            free(root);
            return temp;
        } else if (root->rlink == NULL) {
            Node* temp = root->llink;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->rlink);

        root->val = temp->val;

        root->rlink = deleteNode(root->rlink, temp->val);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, val;

    do {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert Node\n");
        printf("2. Traversals (In-order, Pre-order, Post-order)\n");
        printf("3. Search Element\n");
        printf("4. Find Minimum & Maximum\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("In-order:   ");
                    inOrder(root);
                    printf("\nPre-order:  ");
                    preOrder(root);
                    printf("\nPost-order: ");
                    postOrder(root);
                    printf("\n");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (searchBST(root, val) != NULL)
                    printf("Element %d found in the BST.\n", val);
                else
                    printf("Element %d not found.\n", val);
                break;

            case 4: {
                Node* minNode = findMin(root);
                Node* maxNode = findMax(root);
                if (minNode != NULL && maxNode != NULL) {
                    printf("Minimum element: %d\n", minNode->val);
                    printf("Maximum element: %d\n", maxNode->val);
                } else {
                    printf("Tree is empty!\n");
                }
                break;
            }

            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("Node deleted (if it existed).\n");
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
