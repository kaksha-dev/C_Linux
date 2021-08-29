/**
 *  Reverse the linkedlist recursively
 * Compliation: gcc -o reverse list.c reverse_rec.c
 */

#include <stdio.h>
#include <assert.h>

#include "list.h"

struct node* reverse (struct node *head);
struct node* reverse_util (struct node *head,struct node *before,struct node *current);

struct node* reverse (struct node *head) {
    if (head == NULL) {
        return head;
    }

    head = reverse_util(head,NULL,head);
    
    return head;
}

struct node* reverse_util(struct node *head,struct node *before,struct node *current){
   
    if (current->next == NULL) {
        head = current;
        current->next = before;
        return head;
    }
    
    struct node *after = current->next; 
    current->next = before;
    
    return reverse_util(head, current, after);

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