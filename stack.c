/**
 * Stack operations push, pop,peek,isempty - O(1)
 * Compilation: gcc -o stack stack.c
 * Execution:  ./stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

// node 
typedef struct node {
    int value;          
    struct node *next;  
}node;

// function prototypes
bool is_empty (node *top);
int peek (node *top);
void push (node **top, int value);
int pop (node **top);

// Returns true if stack is empty
bool is_empty (node *top) {
    if (top == NULL) {
        return true;
    }

    return false;
}

// Return but not remove top. Return INT_MIN if unsuccessful
int peek (node *top) {
    if (is_empty(top)) {
        return INT_MIN;
    }

    return top->value;
}

// Add at top 
void push (node **top, int value) {
    // create node
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        return;
    }
        
    temp->value = value; 
    temp->next = NULL;

    // empty
    if (is_empty(*top)) {
        *top = temp; 
        return;
    }

    // make temp 1st node    
    temp->next = *top;  
    *top = temp;        
}

// Remove and return from top. Return INT_MIN if unsuccessful
int pop (node **top) {
    // empty
    if (is_empty(*top)) {
        return INT_MIN;
    } 

    node *temp = *top; 
    int value = temp->value;  
    *top = temp->next;      
    free(temp);              

    return value;
}

void main () {
    // stack
    node *top = NULL;

    assert(is_empty(top) == true);
    push(&top, 1);
    assert(is_empty(top) == false);
    assert(peek(top) == 1);
    push(&top,2);
    push(&top,5);
    assert(peek(top) == 5);
    assert(pop(&top) == 5);
    assert(peek(top) == 2);
    assert(pop(&top) == 2);
    assert(pop(&top) == 1);
    assert(pop(&top) == INT_MIN);

    // delete stack
    while (top != NULL) {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}

