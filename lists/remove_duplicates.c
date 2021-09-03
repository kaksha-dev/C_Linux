/**
 * Remove all duplicate numbers from sorted list.
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct node* remove_duplicates (struct node *head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // make a fake head
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->value = head->value;
    temp->next = head;
    
    struct node *ptr = temp;
    
    while (ptr->next != NULL && ptr->next->next != NULL) {
        
        // check duplicate 
        if (ptr->next->value == ptr->next->next->value) {
            int duplicate_value = ptr->next->value;

            // remove duplicates 
            while (ptr->next != NULL && ptr->next->value == duplicate_value) {
                struct node *duplicate = ptr->next;
                ptr->next = ptr->next->next;
                free(duplicate);
            }
        } else {
            ptr = ptr->next;
        }
    }
    return temp->next;
}

void main () {
    
    struct node *list1 = NULL;
    add(&list1, 5);
    add(&list1, 4);
    add(&list1, 4);
    add(&list1, 3);
    add(&list1, 3);
    add(&list1, 2);
    add(&list1, 1);
    list1 = remove_duplicates(list1);
    assert(list1->next->next->value == 5);

    struct node *list2 = NULL;
    add(&list2, 3);
    add(&list2, 2);
    add(&list2, 1);
    add(&list2, 1);
    add(&list2, 1);
    list2 = remove_duplicates(list2);
    assert(list2->value == 2);
}
