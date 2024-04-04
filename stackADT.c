#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL;

void push(int);
void pop();
void display();

int main() {
    int choice, value;
    printf("\nStack using linked list::\n");
    while (1) {
        printf("***MENU***\n");
        printf("1. push\n2. pop\n3. display\n4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("ENTER THE VALUE TO BE INSERT: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong selection!!! Try again\n");
        }
    }
    return 0;
}

void push(int value) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top;
    }
    top = newNode;
    printf("\nInsertion is success!!!\n");
}

void pop() {
    if (top == NULL) {
        printf("\nStack empty!!!\n");
    } else {
        struct Node* temp = top;
        printf("\nDeleted element: %d\n", temp->data);
        top = temp->next;
        free(temp);
    }
}

void display() {
    if (top == NULL) {
        printf("\nStack is empty\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
