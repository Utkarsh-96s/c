/*
Practical 8
Question:
Pizza parlor accepting maximum M orders. Orders are served on a first-come-first-served basis using a Queue. Write a program to simulate this system.
*/

#include <stdio.h>
#include <conio.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1;

void enqueue(int order) {
    if(rear == MAX - 1)
        printf("Queue is full!\n");
    else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = order;
        printf("Order %d added.\n", order);
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("No orders to serve!\n");
    else {
        printf("Order %d served.\n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if(front == -1 || front > rear)
        printf("No orders in queue.\n");
    else {
        printf("Current Orders:\n");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

void main() {
    int choice, order;
    clrscr();
    do {
        printf("\n1. Add Order\n2. Serve Order\n3. Display Orders\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter order number: ");
                scanf("%d", &order);
                enqueue(order);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    } while(choice != 4);
    getch();
}
