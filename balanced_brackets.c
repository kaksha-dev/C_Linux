/**
 * Balanced Brackets
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Return true if empty
bool is_empty (int top) {
    if (top == -1) {
        return true;
    }

    return false;
}

// Return but not remove top
char peek (char *stack, int top) {
    if (is_empty(top)) {
        return '0';
    }

    return stack[top];
}

// Add at top 
void push (char *stack, int *top, char value) {
    stack[++(*top)] = value;
}

// Delete from top
char pop (char *stack, int *top) {
    if (is_empty(*top)) {
        return '0';
    }

    int value = stack[*top];
    *top = *top - 1;
    return value;
}

bool balanced_brackets(char *str) {
    
    int n  = strlen(str);

    // stack of max size
    char *stack = (char *)malloc(n * sizeof(char));
    int top = -1;
    
    for(int i = 0; i < n; i++) {
        
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            // add opening bracket to stack
            push(stack, &top, str[i]);

        } else {
            // check if there is opening bracket of same type on top of stack
            if (str[i] == ')' && peek(stack, top) != '(') {
                return false;
            }
        
            if (str[i] == '}' && peek(stack, top) != '{') {
                return false;
            }

            if (str[i] == ']' && peek(stack, top)!= '[') {
                return false;
            }

            pop(stack, &top);
        }
    }
    
    // balanced 
    if (is_empty(top)) {
        return true;
    }

    return false;
}

void main() {
    
    assert(balanced_brackets("{}[]()") == true);
    assert(balanced_brackets("{[()]}") == true);
    assert(balanced_brackets("([(]))}") == false);
    assert(balanced_brackets("))}") == false);
}

