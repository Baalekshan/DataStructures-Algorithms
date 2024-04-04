#include <stdio.h>
#include <stdlib.h>

struct tree {
    int info;
    struct tree *left;
    struct tree *right;
};

struct tree *insert(struct tree *, int);
void inorder(struct tree *);
void postorder(struct tree *);
void preorder(struct tree *);
struct tree *delet(struct tree *, int);
struct tree *search(struct tree *);

int main() {
    struct tree *root;
    int choice, item, item_no;
    root = NULL;

    do {
        do {
            printf("\n\t1. Insert in Binary search tree ");
            printf("\n\t2. Delete from Binary search tree ");
            printf("\n\t3. Inorder traversal of Binary search tree");
            printf("\n\t4. Postorder traversal of Binary search tree");
            printf("\n\t5. Preorder traversal of Binary search tree");
            printf("\n\t6. Search and replace ");
            printf("\n\t7. Exit ");
            printf("\n\tEnter choice: ");
            scanf("%d", &choice);
            if (choice < 1 || choice > 7)
                printf("\n\tInvalid choice - try again");
        } while (choice < 1 || choice > 7);

        switch (choice) {
            case 1:
                printf("\n\tEnter new element: ");
                scanf("%d", &item);
                root = insert(root, item);
                printf("\n\tRoot is %d", root->info);
                printf("\n\tInorder traversal of Binary search tree is: ");
                inorder(root);
                break;

            case 2:
                printf("\n\tEnter the element to be deleted: ");
                scanf("%d", &item_no);
                root = delet(root, item_no);
                inorder(root);
                break;

            case 3:
                printf("\n\tInorder traversal of Binary search tree is: ");
                inorder(root);
                break;

            case 4:
                printf("\n\tPostorder traversal of Binary search tree is: ");
                postorder(root);
                break;

            case 5:
                printf("\n\tPreorder traversal of Binary search tree is: ");
                preorder(root);
                break;

            case 6:
                printf("\n\tSearch and replace operation in Binary search tree ");
                root = search(root);
                break;

            default:
                printf("\n\tEnd of program ");
        }
    } while (choice != 7);

    return 0;
}

struct tree *insert(struct tree *root, int x) {
    if (!root) {
        root = (struct tree *)malloc(sizeof(struct tree));
        root->info = x;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (root->info > x)
        root->left = insert(root->left, x);
    else {
        if (root->info < x)
            root->right = insert(root->right, x);
    }
    return root;
}

void inorder(struct tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf(" %d", root->info);
        inorder(root->right);
    }
}

void postorder(struct tree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->info);
    }
}

void preorder(struct tree *root) {
    if (root != NULL) {
        printf(" %d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

struct tree *delet(struct tree *ptr, int x) {
    struct tree *p1, *p2;
    if (!ptr) {
        printf("\n\tNode not found ");
        return ptr;
    } else {
        if (ptr->info < x)
            ptr->right = delet(ptr->right, x);
        else if (ptr->info > x) {
            ptr->left = delet(ptr->left, x);
            return ptr;
        } else {
            if (ptr->info == x) {
                if (ptr->left == ptr->right) {
                    free(ptr);
                    return (NULL);
                } else if (ptr->left == NULL) {
                    p1 = ptr->right;
                    free(ptr);
                    return p1;
                } else if (ptr->right == NULL) {
                    p1 = ptr->left;
                    free(ptr);
                    return p1;
                } else {
                    p1 = ptr->right;
                    p2 = ptr->right;
                    while (p1->left != NULL)
                        p1 = p1->left;
                    p1->left = ptr->left;
                    free(ptr);
                    return p2;
                }
            }
        }
    }
    return (ptr);
}

struct tree *search(struct tree *root) {
    int no, i, ino;
    struct tree *ptr;
    ptr = root;
    printf("\n\tEnter the element to be searched: ");
    scanf(" %d", &no);
    while (ptr) {
        if (no > ptr->info)
            ptr = ptr->right;
        else if (no < ptr->info)
            ptr = ptr->left;
        else
            break;
    }
    if (ptr) {
        printf("\n\tElement %d which was searched is found and is = %d", no, ptr->info);
    } else {
        printf("\n\tElement %d does not exist in the Binary search tree", no);
    }
    return root;
}
