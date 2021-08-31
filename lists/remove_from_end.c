/**
 * Remove nth node from the end of the list
 * gcc -o list list.c remove_from_end.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

// Returns the value that was removed
int remove_n_from_end (struct node **head, int n) {
    // empty 
    if (*head == NULL) {
        return -1;
    }
        
    // one node 
    if ((*head)->next == NULL && n == 1) {
        struct node *temp = *head;
        int ans = temp->value;
        (*head) = NULL;
        free(temp);
       
        return ans;
    }
    
    struct node *fast = *head;
    struct node *slow = *head;
    
    // move fast n from the begining
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    
    // (size - n) = 0, so delete first node
    if (fast == NULL) {
        struct node *temp = *head;
        int ans = temp->value;
        (*head) = (*head)->next;
        free(temp);
       
        return ans;
    }

    // take slow to (size - n) node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
 
    // remove node at (size - n) + 1 position
    struct node *temp = slow->next;
    int ans = temp->value;
    slow->next = slow->next->next;
    free(temp);
    return ans;
}

void main () {
    
    struct node *list1 = NULL;
    for (int i = 1; i <= 10; i++) 
        add(&list1, i);
    assert(remove_n_from_end(&list1,4) == 4); 
     
    struct node *list2 = NULL;
    add(&list2,1);
    assert(remove_n_from_end(&list2,1) == 1); 
    
    struct node *list3 = NULL;
    add(&list3,1);
    add(&list3,2);
    assert(remove_n_from_end(&list3,2) == 2); 

    struct node *list4 = NULL;
    for (int i = 1; i <= 10; i++) 
        add(&list4, i);
    assert(remove_n_from_end(&list4,10) == 10); 

    delete_list(&list1);
    delete_list(&list2);
    delete_list(&list3);
    delete_list(&list4);
}