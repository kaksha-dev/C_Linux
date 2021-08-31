/**
 * Return the node where cycle begins in list. If there is no cycle return NULL.
 * gcc -o list list.c detect_cycle.c
 */

#include <stdio.h>
#include <assert.h>

#include "list.h"

struct node *detect_cycle(struct node *head);

// cycle detection
struct node *detect_cycle (struct node *head) {
    if (head == NULL) {
        return NULL;   
    }
    
    struct node *hare = head, *turtle = head;
    
    while (hare != NULL && turtle != NULL) {  
        // turtle 1 step
        turtle = turtle->next;  
        
        // last node
        if (hare->next == NULL) {
            return NULL;
        }
        //hare 2 steps        
        hare = hare->next->next; 
        
        // cycle -both meet
        if (hare == turtle) {
            // turtle point to head
            turtle = head; 
            
            while (turtle != hare) {
                // both 1 step
                hare = hare->next;
                turtle = turtle->next;
            }
            return turtle;
        }
        
    }
    return NULL;       
}

void main () {
    
    struct node *list1 = NULL;
    add(&list1, 2);
    add(&list1, 1);
    list1->next->next = list1;  
    assert((detect_cycle(list1))->value == 1);

    struct node *list2 = NULL;
    add(&list2, -4);
    add(&list2, 0);
    add(&list2, 2);
    add(&list2, 3);
    list2->next->next->next->next = list2->next;  
    assert((detect_cycle(list2))->value == 2);

    struct node *list3 = NULL;
    add(&list3, 1);
    add(&list3, 2);
    assert(detect_cycle(list3)== NULL);
}