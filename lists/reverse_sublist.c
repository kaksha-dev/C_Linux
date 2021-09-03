/**
 * Reverse the nodes from position left to position right. 
 * Constraints: length >=1, 1 <= left <= right <= length
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct node* reverse_sublist (struct node *head, int left, int right) {

    if (left == right) {
        return head;
    }

    struct node *before_left = NULL;  
    struct node *ptr = head;
    struct node *front_node = NULL;
    
    struct node *prev = NULL; // for reversing sublist
    
    // move till right position
    for (int i = 1; i <= right; i++) {
        
        if (i < left) {
            // node before left position
            before_left = ptr;
            ptr = ptr->next;
        } else {
          
            if (i == left) {
                // node at left position
                front_node = ptr;
            }
            
            // reverse till right position
            struct node *after = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = after;
        }
    }
    // ptr - node after right position
    // prev - node initially at right position
    
    if (left == 1) {
        head = prev;
    } else {
        before_left->next = prev;
    }

    front_node->next = ptr;
    
    return head;
}

void main () {
    
    struct node *list1 = NULL; 
    for (int i = 5; i >= 1; i--) 
        add(&list1, i);
    list1 = reverse_sublist(list1,2,4);
    assert(list1->next->value == 4);
    assert(list1->next->next->next->value == 2);

    struct node *list2 = NULL;
    add(&list2,5);
    list2 = reverse_sublist(list2,1,1);
    assert(list2->value == 5);

    struct node *list3 = NULL;
    for (int i = 10; i >= 1; i--) 
        add(&list3, i);
    list3 = reverse_sublist(list3,1,10);
    assert(list3->value == 10);
    assert(list3->next->next->value == 8);

    delete_list(&list1);
    delete_list(&list2);
    delete_list(&list3);
}