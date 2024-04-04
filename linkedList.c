#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node* LIST;

int insert(LIST head, int ele, int pos) {
    if (pos < 1) {
        printf("Invalid position");
        return 0;
    }

    LIST temp, t;
    temp = (LIST)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed");
        return 0;
    }

    temp->data = ele;
    t = head;
    for (int i = 0; i < pos - 1 && t != NULL; i++) {
        t = t->next;
    }

    if (t == NULL) {
        printf("Position %d is out of range", pos);
        free(temp);
        return 0;
    }

    temp->next = t->next;
    t->next = temp;
    return 1;
}

void display(LIST head) {
    LIST t = head->next;
    while (t != NULL) {
        printf("%d\t", t->data);
        t = t->next;
    }
}

int search(int ele, LIST head) {
    LIST t = head->next;
    while (t != NULL) {
        if (t->data == ele) {
            printf("%d\t", t->data);
            return 1;
        }
        t = t->next;
    }
    return 0;
}

int delet(int pos, LIST head) {
    if (pos < 1) {
        printf("Invalid position");
        return 0;
    }

    LIST t = head;
    for (int i = 1; i < pos && t->next != NULL; i++) {
        t = t->next;
    }

    if (t->next == NULL) {
        printf("Position %d is out of range", pos);
        return 0;
    }

    LIST temp = t->next;
    t->next = temp->next;
    free(temp);
    return 1;
}

int main() {
    LIST head, t;
    head = (LIST)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    head->next = NULL;

    int choice, ele, pos;
    while (1) {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Search");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                if (!insert(head, ele, pos))
                    printf("Failed to insert element\n");
                break;

            case 2:
                printf("List contents: ");
                display(head);
                break;

            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &ele);
                if (search(ele, head))
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;

            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                if (!delet(pos, head))
                    printf("Failed to delete element\n");
                break;

            case 5:
                free(head);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
