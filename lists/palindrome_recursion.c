/**
 * Paildrome or not - using recursion
 * gcc -o list list.c palindrome_recursion.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

bool is_palindrome (struct node *head);
bool is_palindrome_util (struct node *node, struct node **front_node);

// Returns true if given list is palindrome
bool is_palindrome (struct node *head) {
    bool ans = is_palindrome_util(head, &head);
    return ans;
}

bool is_palindrome_util (struct node *node, struct node **front_node) {
    // end 
    if (node == NULL) {
        return true;
    }
    
    // recursively move till the last node 
    if (!is_palindrome_util(node->next,front_node)) {
        return false;
    }
    
    // checks last with front, second second last with second and so on
    if (node->value != (*front_node)->value) {
        return false;
    }
    
    // move front node to next node
    (*front_node) = (*front_node)->next;
    
    return true;
}

void main() {

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