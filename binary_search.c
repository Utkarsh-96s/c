/*
Practical 2
Question:
Write a program to store roll numbers of students in an array who attended training programs in sorted order. Write a function for searching whether a particular student attended a training program or not, using Binary search.
*/

#include <stdio.h>
#include <conio.h>

void main() {
    int roll[100], n, i, low, high, mid, search, found = 0;
    clrscr();
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter roll numbers in sorted order:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &roll[i]);
    printf("Enter roll number to search: ");
    scanf("%d", &search);
    low = 0; high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(roll[mid] == search) {
            found = 1;
            break;
        } else if(search < roll[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(found)
        printf("Student attended the training program.\n");
    else
        printf("Student did not attend the training program.\n");
    getch();
}
