/**
 * list - class problems
 */

#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

// length of list 
int size (struct node *head) {
    int size = 0;
    struct node *ptr = head;

    while (ptr != NULL) {
        size ++;
        ptr = ptr->next;
    }
    return size;
}

// add at begining
void add(struct node **head, int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
        return;

    temp->value = value; 
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp; 
        return;
    }
        
    temp->next = *head;  
    *head = temp;       
    
}

// delete entire list
void delete_list (struct node **head) {
    
    while (*head != NULL) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

