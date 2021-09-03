/**
 * Largest rectangle in histogram
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

// stack
void push (int *array, int *top, int value) {
    *top = *top + 1;
    array[*top] = value; 
}

int pop (int *array, int *top) {
    if (is_empty(top))
        return -1;

    int value = array[*top];
    *top = *top - 1;
    return value;
}

bool is_empty (int top) {
    if (top == -1) {
        return true;
    }
    return false;
}

int peek (int *array, int top) {
    return array[top];    
}

// find maximum
int find_max (int a, int b) {
    if (a >= b) 
        return a;
    return b;
}

int largest_rectangle(int *heights, int heightsSize) {

    int *stack = (int *)malloc(heightsSize * sizeof(int));  //stack
    int top = -1;
    
    int  max_area = 0;
    
    int i = 0;
    while (i < heightsSize) {
        
        if (is_empty(top) || heights[i] >= heights[peek(stack, top)]) {
            // greater element - process later
            push(stack, &top, i);
            i++;
        }
        else {
            // pop stack until an area with smaller height that current one found
            int current = heights[pop(stack, &top)]*(is_empty(top)? i : i - peek(stack, top) - 1);
            max_area = find_max(current, max_area);  
        }   
    }
    
    //pop remaining to check area
    while (!is_empty(top)) {
        int current = heights[pop(stack, &top)]*(is_empty(top)? i : i - peek(stack, top)-1);
        max_area = find_max(current, max_area);
    }

    free(stack);
    
    return max_area;
}

void main () {
    int array[] = {2,1,5,6,2,3};
    assert(largest_rectangle(array, 6) == 10);

    int array2[] = {2,1};
    assert(largest_rectangle(array2, 2) == 2);

    int array3[] = {3,2,5,6,1,4,4};
    assert(largest_rectangle(array3, 7) == 10);

    int array4[] = {2,1,5,6,2,3};
    assert(largest_rectangle(array3, 6) == 10);
}