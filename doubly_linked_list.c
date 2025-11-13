/*
Practical 6
Question:
Write a program to implement Doubly Linked List with the following functions: Create, Add, Display.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
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
        newnode->prev = NULL;
        if(head == NULL)
            head = newnode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }
        printf("Do you want to add another node? (1/0): ");
        scanf("%d", &choice);
    } while(choice);

    printf("\nDoubly Linked List:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    getch();
}
