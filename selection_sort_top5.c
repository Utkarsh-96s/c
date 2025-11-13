/*
Practical 3
Question:
Write a program to store the first-year percentage of students in an array. Write a function for sorting the array of floating-point numbers in ascending order using Selection Sort and display the top five scores.
*/

#include <stdio.h>
#include <conio.h>

void main() {
    float marks[100], temp;
    int n, i, j, min;
    clrscr();
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter percentages:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &marks[i]);

    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(marks[j] < marks[min])
                min = j;
        }
        temp = marks[i];
        marks[i] = marks[min];
        marks[min] = temp;
    }

    printf("\nTop Five Scores:\n");
    for(i = n-1; i >= n-5 && i >= 0; i--)
        printf("%.2f\n", marks[i]);
    getch();
}
