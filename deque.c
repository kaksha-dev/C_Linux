/**
 * Deque operations add_head, add_tail, remove_head, remove_tail, peek_head,peek_tail, is_empty - O(1)
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
    struct node *prev;
}node;
 
// function prototypes
bool is_empty (node *head, node *tail);
int peek_head (node *head, node *tail);
int peek_tail (node *head, node *tail);
node* create (int value);
void add_head (node **head, node **tail, int value);
void add_tail (node **head, node **tail, int value);
int remove_head (node **head, node **tail);
int remove_tail (node **head, node **tail);

// Returns true if deque is empty 
bool is_empty (node *head, node *tail) {
    if (head == NULL && tail == NULL) {
        return true;
    }

    return false;
}

// Return but not remove head. Return INT_MIN if unsuccessful
int peek_head (node *head, node *tail) {
    if (is_empty(head, tail)) {
        return INT_MIN;
    }

    return head->value;
}

// Return but not remove tail. Return INT_MIN if unsuccessful
int peek_tail (node *head, node *tail) {
    if (is_empty(head, tail)) {
        return INT_MIN;
    }

    return tail->value;
}

// create node
node* create (int value) {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        return NULL;
    }

    temp->value = value;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// Add at head 
void add_head (node **head, node **tail, int value) {
    node *temp = create(value);
    if (temp == NULL) {
        return;
    }

    // empty
    if (is_empty(*head, *tail)) {
        *head = *tail = temp;
        return;
    } 

    // make temp 1st
    temp->next = *head;  
    (*head)->prev = temp;
    *head = temp;
}

// Add at tail 
void add_tail (node **head, node **tail, int value) {
    node *temp = create(value);
    if (temp == NULL) {
        return;
    }

    // empty
    if (is_empty(*head, *tail)) {
        *head = temp;
        *tail = temp;
        return;
    } 

    // make temp last node
    temp->prev = *tail;
    (*tail)->next = temp;
    *tail = temp;
}

// Remove and return from head. Return INT_MIN if unsuccessful
int remove_head (node **head, node **tail) {
    // empty
    if (is_empty(*head, *tail)) {
        return INT_MIN;
    } 

    // one node
     if ((*head)->next == NULL) {  
        node *temp = *head; 
        int value = temp->value;  
        *head = *tail = NULL;    
        free(temp); 
        return value; 
    }    
    
    // 2nd node
    node *temp = *head; 
    int value = temp->value;  
    *head = temp->next;  
    temp->next->prev = NULL;    
    free(temp); 

    return value;
}

// Remove and return from tail. Return INT_MIN if unsuccessful
int remove_tail (node **head, node **tail) {
    // empty
    if (is_empty(*head, *tail)) {
        return INT_MIN;
    } 

    // one node
     if ((*head)->next == NULL) {  
        node *temp = *head; 
        int value = temp->value;  
        *head = *tail = NULL;    
        free(temp); 
        return value; 
    }    
    
    // 2nd last
    node *temp = *tail; 
    int value = temp->value;  
    *tail = (*tail)->prev;
    (*tail)->next = NULL;    
    free(temp); 

    return value;
}


void main () {
    // deque
    node *head = NULL;
    node *tail = NULL;
    

    assert(is_empty(head, tail) == true);
    add_head(&head, &tail, 1);
    assert(remove_head(&head, &tail) == 1);
    add_tail(&head, &tail, 1);
    add_head(&head,&tail,2);
    add_head(&head,&tail,4);
    add_tail(&head,&tail,5);
    assert(peek_head(head, tail) == 4);
    assert(peek_tail(head, tail) == 5);
    assert(is_empty(head, tail) == false);
    assert(remove_head(&head, &tail) == 4);
    assert(remove_tail(&head, &tail) == 5);
    assert(remove_tail(&head, &tail) == 1);
    assert(remove_tail(&head, &tail) == 2);
    assert(is_empty(head, tail) == true);
}