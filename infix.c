/**
 * Convert valid arithmetic expression to postfix notation. Input string includes only numbers (0-9) and mathemical symbols. Input string doesn't include whitespaces.
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

// get the precedence of operators.
int precedence (char c) {
    if(c == '^') {
        return 2;  
    } else if(c == '/' || c == '*') {
        return 1;
    } else if(c == '+' || c == '-') {
        return 0;
    }
    
    return -1;
}


char* infix(char *str, int n) {
    
    // stack
    char *stack = (char *)malloc(n * sizeof(char));
    int top = -1;
    
    char *ans = (char *)malloc((n + 1) * sizeof(char));
    int j = 0;
    
    for(int i = 0; i < n; i++) {
        
        if(str[i] >= '0' && str[i] <= '9') {
            // add number to ans    
            ans[j++] = str[i];
            
        } else if(str[i] == '(') {
            // add opening bracket to stack
            push(stack, &top, '(');
            
        } else if(str[i] == ')') {
            
            // pop all elements untill opening bracket is encountered
            while(peek(stack, top) != '(') {
                ans[j++] = pop(stack, &top);
            }
            
            pop(stack, &top);
            
        } else {
            // if opertor at top has precedence greater than that or equal to that of the scanned operator, then pop
            while(!is_empty(top) && precedence (peek(stack, top)) >= precedence (str[i])) {
                ans[j++] = pop(stack, &top);
            }
            
            push(stack, &top, str[i]);
        }
    }
    
    // remaining operators
    while(!is_empty(top)) {
        ans[j++] = pop(stack, &top);
    }
    
    ans[j++] = '\0';
    
    free(stack);

    return ans;
}

int main() {
    char *str = "(3^2*5)/(3*2-3)+5";
    char *ans = infix(str, strlen(str));
    assert(strcmp(ans, "32^5*32*3-/5+") == 0);

    str = "(4+2)*7-8+1";
    ans = infix(str, strlen(str));
    assert(strcmp(ans, "42+7*8-1+") == 0);

}
