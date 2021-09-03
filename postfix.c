/**
 * Evaluate a valid postfix expression. Input string includes only numbers (0-9) and mathemical symbols. Input string doesn't include whitespaces.4
 * gcc -o postfix postfix.c -lm
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

// Return true if empty
bool is_empty (int top) {
    if (top == -1) {
        return true;
    }

    return false;
}

// Return but not remove top
int peek (int *stack, int top) {
    if (is_empty(top)) {
        return INT_MIN;
    }

    return stack[top];
}

// Add at top 
void push (int *stack, int *top, int value) {
    stack[++(*top)] = value;
}

// Delete from top
int pop (int *stack, int *top) {
    if (is_empty(*top)) {
        return INT_MIN;
    }

    int value = stack[*top];
    *top = *top - 1;
    return value;
}

// mathematical operations
int operation (int operator, int num1, int num2) {
    if (operator == '+') {
        return num1 + num2;
    }
    if (operator == '-') {
        return num1 - num2;
    }
    if (operator == '*') {
        return num1 * num2;
    }
    if (operator == '/') {
        return num1 / num2;
    }
    if (operator == '^') {
        return (int)pow(num1, num2);
    }
}

int postfix(char *str, int n) {

    // stack of max size
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;

    for(int i = 0; i < n; i++) {
        
        if (str[i] ==  '+' || str[i] ==  '-' || str[i] ==  '*' || 
            str[i] ==  '/' || str[i] == '^' ) {
        
                // pop two numbers and perform operation on them
                // add result to stack
                int num2 = pop(stack, &top);
                int num1 = pop(stack, &top);
                int ans = operation(str[i], num1, num2);
    
                push(stack, &top, ans);
        } else {
                // add number to stack
                push(stack, &top, str[i] - '0');
        }
    }

    int ans = stack[top];
  
    free(stack);
    
    return ans;
}

int main() {
    char *str = "32^5*32*3-/5+";
    assert(postfix(str,strlen(str)) == 20);

    str = "42+7*8-1+";
    assert(postfix(str, strlen(str)) == 35);
}
