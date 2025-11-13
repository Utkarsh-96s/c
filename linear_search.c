/*
Practical 1
Question:
Write a program to store roll numbers of students in an array who attended a training program in random order. Write a function for searching whether a particular student attended a training program or not, using Linear search.
*/

#include <stdio.h>
#include <conio.h>

void main() {
    int roll[100], n, i, search, found = 0;
    clrscr();
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter roll numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &roll[i]);
    printf("Enter roll number to search: ");
    scanf("%d", &search);
    for(i = 0; i < n; i++) {
        if(roll[i] == search) {
            found = 1;
            break;
        }
    }
    if(found)
        printf("Student attended the training program.\n");
    else
        printf("Student did not attend the training program.\n");
    getch();
}
