/**
 * Paildrome or not
 * gcc -o list list.c palindrome.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

struct node* reverse (struct node *node);
bool is_palindrome (struct node *head);

// Returns true if given list is palindrome
bool is_palindrome (struct node *head) {

    if (head == NULL || head->next == NULL) {
        return true;
    }
        
    // find mid
    // odd length, size of first half is one more than second half
    struct node *hare = head, *turtle = head;
    
    while (hare->next != NULL && hare->next->next != NULL) {
        // turtle 1 step
        turtle = turtle->next;
        // hare 2 steps
        hare = hare->next->next;
    }
    hare = NULL;
    
    // reverse the second half
    // turtle points to last node of first half 
    struct node *reverse_node = reverse(turtle->next);
   
    // check palindrome
    struct node *first = head;
    struct node *second = reverse_node;
    bool ans = true;
    
    while (second != NULL) {
        if (first->value != second->value) {
            ans = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    
    // reverse the second half again - to original
    turtle->next = reverse(reverse_node);
    
    return ans;
}

// reverse list
struct node* reverse (struct node *node) {

    if (node == NULL || node->next == NULL) {
        return node;
    }
        
    struct node *before = NULL, *after = NULL, *current = node; 
      
    while (current != NULL) {  
        after = current->next; 
        current->next = before;  
        before = current; 
        current = after; 
    }
    
    // last  node
    node = before;  
    return node;
}

void main () {

    struct node *list1 = NULL;
    add(&list1,1);
    add(&list1,2);
    assert(is_palindrome(list1) == false);  //1-2

    struct node *list2 = NULL;
    add(&list2,1);
    add(&list2,2);
    add(&list2,2);
    add(&list2,1);
    assert(is_palindrome(list2) == true);  //1-2-2-1

    struct node *list3 = NULL;
    add(&list3,1);
    add(&list3,2);
    add(&list3,3);
    add(&list3,2);
    add(&list3,1);
    assert(is_palindrome(list3) == true);  //1-2-3-2-1

    delete_list(&list1);
    delete_list(&list2);
    delete_list(&list3);
}