#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* llink;
    struct Node* rlink;
} Node;

Node* createTree(int val) {
    if (val == -1)
        return NULL;
    Node* nn = (Node*)malloc(sizeof(Node));
    if (nn == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    nn->val = val;
    int leftVal, rightVal;

    printf("\nEnter the value of left child for %d (-1 for no left child): ", val);
    scanf("%d", &leftVal);
    nn->llink = createTree(leftVal);

    printf("\nEnter the value of right child for %d (-1 for no right child): ", val);
    scanf("%d", &rightVal);
    nn->rlink = createTree(rightVal);

    return nn;
}

void inOrder(Node* root) {
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;
    Node* curr = root;

    while (curr != NULL || top >= 0) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->llink;
        }

        curr = stack[top--];
        printf("%d ", curr->val);

        curr = curr->rlink;
    }
}

void preOrder(Node* root) {
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        Node* curr = stack[top--];
        printf("%d ", curr->val);

        if (curr->rlink != NULL)
            stack[++top] = curr->rlink;
        if (curr->llink != NULL)
            stack[++top] = curr->llink;
    }
}

void postOrder(Node* root) {
    if (root == NULL) return;

    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        Node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->llink != NULL)
            stack1[++top1] = curr->llink;
        if (curr->rlink != NULL)
            stack1[++top1] = curr->rlink;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->val);
    }
}

void printParent(Node* root, int target) {
    if (root == NULL)
        return;

    if (root->val == target) {
        printf("Node %d is the root and has no parent.\n", target);
        return;
    }

    if ((root->llink != NULL && root->llink->val == target) ||
        (root->rlink != NULL && root->rlink->val == target)) {
        printf("The parent of %d is: %d\n", target, root->val);
        return;
    }

    printParent(root->llink, target);
    printParent(root->rlink, target);
}

int findDepth(Node* root) {
    if (root == NULL) {
        return -1;
    }

    int leftDepth = findDepth(root->llink);
    int rightDepth = findDepth(root->rlink);

    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}

void printDepth(Node* root) {
    if (root == NULL) {
        printf("Empty tree\n");
        return;
    }

    int depth = findDepth(root);
    printf("The Depth of the tree is %d\n", depth);
}

int printAncestors(Node* root, int target) {
    if (root == NULL)
        return 0;

    if (root->val == target)
        return 1;

    if (printAncestors(root->llink, target) || printAncestors(root->rlink, target)) {
        printf("%d ", root->val);
        return 1;
    }

    return 0;
}

int countLeaves(Node* root) {
    if (root == NULL)
        return 0;

    if (root->llink == NULL && root->rlink == NULL)
        return 1;

    return countLeaves(root->llink) + countLeaves(root->rlink);
}

void levelOrder(Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* curr = queue[front++];
        printf("%d ", curr->val);

        if (curr->llink != NULL) {
            queue[rear++] = curr->llink;
        }

        if (curr->rlink != NULL) {
            queue[rear++] = curr->rlink;
        }
    }
}
int main() {
    Node* root = NULL;
    int rootVal;

    printf("--- Binary Tree Creation ---\n");
    printf("Enter the root value (-1 for empty tree): ");
    scanf("%d", &rootVal);
    root = createTree(rootVal);

    if (root == NULL) {
        printf("\nTree is empty.\n");
        return 0;
    }

    printf("\n--- Traversals ---");
    printf("\nPre-order:   ");
    preOrder(root);

    printf("\nIn-order:    ");
    inOrder(root);

    printf("\nPost-order:  ");
    postOrder(root);

    printf("\nLevel-order: ");
    levelOrder(root);
    printf("\n");

    printDepth(root);

    printf("Number of leaf nodes: %d\n", countLeaves(root));

    int target;
    printf("\nEnter a node value to find its parent: ");
    scanf("%d", &target);
    printParent(root, target);

    printf("Enter a node value to print its ancestors: ");
    scanf("%d", &target);
    printf("Ancestors of %d: ", target);
    if (!printAncestors(root, target)) {
        printf("Node not found or is root.");
    }
    printf("\n");

    return 0;
}
