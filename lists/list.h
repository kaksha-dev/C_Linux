/**
 * list - class problems
 */

#ifndef LIST
#define LIST

// node
struct node {
    int value;          
    struct node *next;  
};

int size (struct node *head);
void add(struct node **head, int value);
void delete_list (struct node **head);

#endif