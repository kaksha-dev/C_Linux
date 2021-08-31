/**
 * Merge two linked lists sorted in non decreasing order and return it as a sorted list.
 * gcc -o list list.c merge_sorted_list.c
 */

#include <stdio.h>
#include <assert.h>

#include "list.h"

struct node *merge_list (struct node *A, struct node *B);
struct node *merge_util(struct node *A, struct node *B);
void display (struct node *head);

struct node* merge_list(struct node* A, struct node* B){
    struct node *ans = merge_util (A, B);
    return ans;
}

struct node* merge_util (struct node* A, struct node* B) {
    // empty
    if (A == NULL) {
        return B;
    }
    if (B == NULL) {
        return A;
    }
    
    // keep smaller one and recursively find next greater
    if (A->value <= B->value) {
        A->next = merge_util(A->next, B);
        return A;
    } else {
        B->next = merge_util(A, B->next);
        return B;
    }
    
    return NULL;
}

// prints the list
void display (struct node *head) {
    if (head == NULL)
        return;
    
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d\t", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}
void main() {

    struct node *list1 = NULL;  // 1 1 3 6 7 10 
    add(&list1,10);
    add(&list1,7);
    add(&list1,6);
    add(&list1,3);
    add(&list1,1);
    add(&list1,1);

    struct node *list2 = NULL;  // 1 2 3 8 
    add(&list2,8);
    add(&list2,3);
    add(&list2,2);
    add(&list2,1);

   display(merge_list(list1, list2));

    struct node *list3 = NULL;
    struct node *list4 = NULL;
    display(merge_list(list3, list4));
    add(&list4, 6);
    add(&list4,2);
    display(merge_list(list3, list4));    
}