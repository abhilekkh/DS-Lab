
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


typedef struct CharNode {
    char data;
    struct CharNode* next;
} CharNode;

void pushChar(CharNode** top, char c) {
    CharNode* newNode = (CharNode*)malloc(sizeof(CharNode));
    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}

char popChar(CharNode** top) {
    if (*top == NULL) return '\0';
    CharNode* temp = *top;
    char val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

char peekChar(CharNode* top) {
    if (top == NULL) return '\0';
    return top->data;
}

int isCharEmpty(CharNode* top) {
    return top == NULL;
}

typedef struct DoubleNode {
    double data;
    struct DoubleNode* next;
} DoubleNode;

void pushDouble(DoubleNode** top, double d) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->data = d;
    newNode->next = *top;
    *top = newNode;
}

double popDouble(DoubleNode** top) {
    if (*top == NULL) return 0;
    DoubleNode* temp = *top;
    double val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    CharNode* top = NULL;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            pushChar(&top, c);
        } else if (c == ')') {
            while (!isCharEmpty(top) && peekChar(top) != '(') {
                postfix[j++] = popChar(&top);
            }
            popChar(&top);
        } else {
            while (!isCharEmpty(top) && precedence(peekChar(top)) >= precedence(c)) {
                postfix[j++] = popChar(&top);
            }
            pushChar(&top, c);
        }
        i++;
    }

    while (!isCharEmpty(top)) {
        postfix[j++] = popChar(&top);
    }
    postfix[j] = '\0';
}

double evaluatePostfix(char* postfix) {
    DoubleNode* top = NULL;
    int i = 0;

    while (postfix[i] != '\0') {
        char c = postfix[i];

        if (isdigit(c)) {
            pushDouble(&top, (double)(c - '0'));
        } else {
            double val2 = popDouble(&top);
            double val1 = popDouble(&top);

            switch (c) {
                case '+': pushDouble(&top, val1 + val2); break;
                case '-': pushDouble(&top, val1 - val2); break;
                case '*': pushDouble(&top, val1 * val2); break;
                case '/': pushDouble(&top, val1 / val2); break;
                case '^': pushDouble(&top, pow(val1, val2)); break;
            }
        }
        i++;
    }
    return popDouble(&top);
}

int main() {
    char infix[100], postfix[100];

    printf("=== STACK: INFIX TO POSTFIX & EVALUATION ===\n");
    printf("Enter infix expression (e.g., A+B*C or numeric like 3+5*2): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    char choice;
    printf("Evaluate using numeric digits? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        double result = evaluatePostfix(postfix);
        printf("Evaluated Result: %.2f\n", result);
    }

    return 0;
}
