/**
 * Rotate the list to the right by k places.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct node* rotate_right (struct node *head, int k) {
    
    if (head == NULL || k == 0) {
        return head;
    }
        
	struct node *list_last = head;

    // length
	int length = 1;
	while (list_last->next != NULL) {
        length++;
		list_last = list_last->next;
	}

    // no rotation	
	if (k % length == 0) {
        return head;
    }
	
    // move the list after the (length - k % length)th node to the front
    int new_k = length - k % length;
    struct node *new_last = head;

	for (int i = 1; i < new_k; i++) {
        new_last = new_last->next;
    }
	
    // last node to first node
    list_last->next = head;
    // node after new_k position
	head = new_last->next;
    // node at new_k poition
	new_last->next = NULL;

	return head;
}

void main () {
    
    struct node *list1 = NULL;
    for (int i = 5; i >= 1; i--) 
        add(&list1, i);
    list1 = rotate_right(list1,2);
    assert(list1->value == 4);

    struct node *list2 = NULL;
    add(&list2, 2);
    add(&list2,1);
    add(&list2,0);
    list2 = rotate_right(list2,4);
    assert(list2->value == 2);

    struct node *list3 = NULL;
    for (int i = 6; i >= 1; i--) 
        add(&list3, i);
    list3 =rotate_right(list3,4);
    assert(list3->value == 3);
}