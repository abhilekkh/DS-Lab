#include <stdio.h>
#include <stdlib.h>

typedef struct Pnode{
    int coeff;
    int exp;
    struct Pnode *next;
    struct Pnode *prev;
}P;

void createPolynomial(P** head, int coeff, int exp){
    P* newNode = (P*)malloc(sizeof(P));
    if(newNode == NULL){
        printf("Memory Allocation Failed!");
        return;
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    if(*head == NULL){
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
        printf("\nPnode created at Head");
    }
    else{
        P* temp = *head;
        if(temp->next == *head){
            newNode->prev = *head;
            newNode->next = *head;
            (*head)->prev = newNode;
            (*head)->next = newNode;
            printf("\nPnode created after Head");
        }
        else{
            while(temp->next != *head)
                temp = temp->next;
            newNode->next = *head;
            newNode->prev = temp;
            temp->next = newNode;
            (*head)->prev = newNode;
            printf("\nPnode created at end");
        }
    }
}

void display(P *head){
   if (head == NULL) {
        printf("\nPolynomial is empty.");
        return;
    }

    P* temp = head->prev;
    printf("\nPolynomial: ");
    do {
        printf("%d x^%d", temp->coeff, temp->exp);
        temp = temp->prev;
        if (temp != head->prev) {
            printf(" + ");
        }
    } while (temp != head->prev);
    printf("\n");
}

void addPolynomials(P* head1, P* head2, P** head3) {
    int max1 = (head1 != NULL) ? head1->prev->exp : -1;
    int max2 = (head2 != NULL) ? head2->prev->exp : -1;
    int max_exp = (max1 > max2) ? max1 : max2;

    for (int i = 0; i <= max_exp; i++) {
        int c1 = 0, c2 = 0;
        if (head1 != NULL) {
            P* t = head1;
            do {
                if (t->exp == i) { c1 = t->coeff; break; }
                t = t->next;
            } while (t != head1);
        }
        if (head2 != NULL) {
            P* t = head2;
            do {
                if (t->exp == i) { c2 = t->coeff; break; }
                t = t->next;
            } while (t != head2);
        }
        int sum_coeff = c1 + c2;
        createPolynomial(head3, sum_coeff, i);
    }
}

int main(){
    P* head1 = NULL;
    P* head2 = NULL;

    // Create First Polynomial
    int n, coeff, exp;
    printf("\nEnter the highest degree of polynomial 1: ");
    scanf("%d", &n);
    printf("\nEnter Coefficient of each degree variable: ");
    for(int i = 0; i <= n; i++){
        printf("\nEnter coefficient of %d degree variable: ", i);
        scanf("%d", &coeff);
        exp = i;
        createPolynomial(&head1, coeff, exp);
    }
    printf("\nFirst ");
    display(head1);

    // Create Second Polynomial
    int n2;
    printf("\nEnter the highest degree of polynomial 2: ");
    scanf("%d", &n2);
    printf("\nEnter Coefficient of each degree variable: ");
    for(int i = 0; i <= n2; i++){
        printf("\nEnter coefficient of %d degree variable: ", i);
        scanf("%d", &coeff);
        exp = i;
        createPolynomial(&head2, coeff, exp);
    }
    printf("\nSecond ");
    display(head2);

    // Add both polynomials
    P* head3 = NULL;
    addPolynomials(head1, head2, &head3);
    printf("\nSum ");
    display(head3);

    return 0;
}
