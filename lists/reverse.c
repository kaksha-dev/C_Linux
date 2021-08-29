/**
 *  Reverse the linkedlist
 * Compliation: gcc -o reverse list.c reverse.c
 */

#include <stdio.h>
#include <assert.h>

#include "list.h"

struct node* reverse (struct node *head);

struct node* reverse (struct node *head) {
    // empty 
    if (head == NULL) {
        return head;
    }
    
    // one  node 
    if (head->next == NULL) {
        return head;
    }
    
    struct node *before = NULL, *after = NULL, *current = NULL; 
    
    current = head;
    
    // move till last node 
    // create link to previous one 
    // keep track of next one
    while (current != NULL) {  
        after = current->next; 
        current->next = before;  
        before = current; 
        current = after; 
    }
    
    // last  node
    head = before; 
    
    return head;
}

void main () {
    struct node *head = NULL;

    for (int i = 1; i <= 10; i++) 
        add(&head, i);
    
    assert(head->value == 10);
    head = reverse(head);
    assert(head->value == 1); 
  
    delete_list(&head);
}