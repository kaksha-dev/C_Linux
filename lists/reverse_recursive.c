/**
 * Reverse the linkedlist recursively
 * Compliation: gcc -o reverse list.c reverse_recursive.c
 */

#include <stdio.h>
#include <assert.h>

#include "list.h"

struct node* reverse (struct node *head);
struct node* reverse_util (struct node *current);

struct node* reverse (struct node *head) {
    if (head == NULL) {
        return head;
    }

    head = reverse_util(head);
    
    return head;
}

struct node* reverse_util (struct node *current) {
    if (current == NULL || current->next == NULL) {
        return current;
    }

    struct node *after = current->next;

    struct node *list = reverse(after);

    after->next = current;
    current->next = NULL;
  
    return list;
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