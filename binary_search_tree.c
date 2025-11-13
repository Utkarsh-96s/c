/*
Practical 9
Question:
Construct a Binary Search Tree by inserting the values in the order given. After constructing a binary tree:
 i. Insert new node
 ii. Find number of nodes in longest path from root
 iii. Minimum data value in the tree
 iv. Swap left and right pointers at every node
 v. Search a value.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if(root == NULL)
        return createNode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int height(struct node* root) {
    if(root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int findMin(struct node* root) {
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

void swap(struct node* root) {
    struct node* temp;
    if(root != NULL) {
        swap(root->left);
        swap(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int search(struct node* root, int key) {
    if(root == NULL)
        return 0;
    if(root->data == key)
        return 1;
    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main() {
    struct node* root = NULL;
    int choice, val;
    clrscr();
    do {
        printf("\n1. Insert\n2. Display (Inorder)\n3. Height\n4. Minimum Value\n5. Swap Tree\n6. Search\n7. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                printf("Height = %d\n", height(root));
                break;
            case 4:
                printf("Minimum Value = %d\n", findMin(root));
                break;
            case 5:
                swap(root);
                printf("Tree swapped.\n");
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if(search(root, val))
                    printf("Value found.\n");
                else
                    printf("Value not found.\n");
                break;
        }
    } while(choice != 7);
    getch();
}
