/**
 * Queue operations enqueue, dequeue,peek,isempty - O(1)
 * Compilation: gcc -o queue queue.c
 * Execution:  ./queue
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
bool is_empty (node *head, node *tail);
int peek (node *head);
void enqueue (node **head, node **tail, int value);
int dequeue (node **head, node **tail);

// Returns true if queue is empty
bool is_empty (node *head, node *tail) {
    if (head == NULL && tail == NULL) {
        return true;
    }

    return false;
}

// Return but not remove head. Return INT_MIN if unsuccessful
int peek (node *head) {
    if (head == NULL) {
        return INT_MIN;
    }

    return head->value;
}

// Add at tail 
void enqueue (node **head, node **tail, int value) {
    // create node
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        return;
    }
        
    temp->value = value; 
    temp->next = NULL;

    // empty
    if (is_empty(*head, *tail))  {
        *head = temp;
        *tail = temp;
        return; 
    } 
               
    // make temp last node
    (*tail)->next = temp;  
    *tail = temp;       
}
  

// Remove and return from top. Return INT_MIN if unsuccessful
int dequeue (node **head, node **tail) {
    // empty
    if (is_empty(*head, *tail)) {
        return INT_MIN;
    } 

    // one node
     if ((*head)->next == NULL) {  
        node *temp = *head; 
        int value = temp->value;  
        *head = NULL;
        *tail = NULL;    
        free(temp); 
        return value; 
    }    
    
    node *temp = *head; 
    int value = temp->value;  
    *head = temp->next;      
    free(temp); 

    return value;
}

void main () {
    // queue
    node *head = NULL;
    node *tail = NULL;
    
    assert(is_empty(head, tail) == true);
    enqueue(&head, &tail, 1);
    assert(is_empty(head, tail) == false);
    assert(peek(head) == 1);
    enqueue(&head,&tail,2);
    enqueue(&head,&tail,5);
    assert(peek(head) == 1);
    assert(dequeue(&head, &tail) == 1);
    assert(peek(head) == 2);

    // delete queue
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

