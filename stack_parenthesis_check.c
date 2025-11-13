/*
Practical 7
Question:
In any language program, mostly syntax errors occur due to unbalanced delimiters such as (), {}, []. Write a program using Stack to check whether a given expression is well parenthesized or not.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int isMatchingPair(char left, char right) {
    if(left == '(' && right == ')') return 1;
    if(left == '{' && right == '}') return 1;
    if(left == '[' && right == ']') return 1;
    return 0;
}

void main() {
    char exp[100];
    int i, balanced = 1;
    clrscr();
    printf("Enter expression: ");
    gets(exp);
    for(i = 0; i < strlen(exp); i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == -1 || !isMatchingPair(pop(), exp[i])) {
                balanced = 0;
                break;
            }
        }
    }
    if(top != -1) balanced = 0;
    if(balanced)
        printf("Expression is well parenthesized.");
    else
        printf("Expression is NOT well parenthesized.");
    getch();
}
