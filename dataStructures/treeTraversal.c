#include <stdio.h>
#include <stdlib.h>

struct rec {
    int num;
    struct rec *left;
    struct rec *right;
};

struct rec *tree = NULL;
int count = 1;

struct rec *insert(struct rec *tree, int num);
void preorder(struct rec *tree);
void inorder(struct rec *tree);
void postorder(struct rec *tree);

int main() {
    int choice;
    int digit;
    
    do {
        printf("Enter 1: Insert a node in the BT\n");
        printf("Enter 2: Display (preorder) the BT\n");
        printf("Enter 3: Display (inorder) the BT\n");
        printf("Enter 4: Display (postorder) the BT\n");
        printf("Enter 5: END\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer: To quit enter 0");
                scanf("%d", &digit);
                while (digit != 0) {
                    tree = insert(tree, digit);
                    scanf("%d", &digit);
                }
                break;
            case 2:
                printf("\nPreorder traversing TREE\n");
                preorder(tree);
                break;
            case 3:
                printf("\nInorder traversing TREE\n");
                inorder(tree);
                break;
            case 4:
                printf("\nPostorder traversing TREE\n");
                postorder(tree);
                break;
            case 5:
                puts("END");
                exit(0);
        }
    } while (choice != 5);

    return 0;
}

struct rec *insert(struct rec *tree, int digit) {
    if (tree == NULL) {
        tree = (struct rec *)malloc(sizeof(struct rec));
        tree->left = tree->right = NULL;
        tree->num = digit;
        count++;
    } else if (count % 2 == 0)
        tree->left = insert(tree->left, digit);
    else
        tree->right = insert(tree->right, digit);

    return (tree);
}

void preorder(struct rec *tree) {
    if (tree != NULL) {
        printf("%d\n", tree->num);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(struct rec *tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d\n", tree->num);
        inorder(tree->right);
    }
}

void postorder(struct rec *tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\n", tree->num);
    }
}
