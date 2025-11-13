/*
Practical 5
Question:
Write a program to implement Singly Linked List with the following functions: Create, Add, Display.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void main() {
    struct node *head = NULL, *temp, *newnode;
    int choice;
    clrscr();
    do {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
            head = newnode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
        printf("Do you want to add another node? (1/0): ");
        scanf("%d", &choice);
    } while(choice);

    printf("\nLinked List:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    getch();
}
