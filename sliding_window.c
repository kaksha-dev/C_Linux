/**
 * sliding window maximum 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

// circular deque
int *deque = NULL;
int capacity = 1;
int head = -1, tail = -1;

// Return true if empty
bool is_empty () {  
    if (head == -1) {
        return true;
    }

    return false;
}

// Return true if full
bool is_full () {
    if ((tail + 1) % capacity == head) {
        return true;
    }

    return false;
}

// Remove and not return head. Return INT_MIN if unsuccessful
int peek_head() {
    if(is_empty()) {
        return INT_MIN;
    }
    
    return deque[head];
}

// Remove and not return tail. Return INT_MIN if unsuccessful
int peek_tail() {
    if(is_empty()) {
        return INT_MIN;
    }
    
    return deque[tail];
}

// Add at tail
void add_tail(int value) {
    if(is_full()) {
        return;
    }

    // empty
    if (head == -1) {
        head = 0;
    }    
    
    tail = (tail + 1) % capacity;
    deque[tail] = value; 
}

// Remove head
int remove_head() {
    if(is_empty()) {
        return INT_MIN;
    }
    
    int value = deque[head];
    
    // one element
    if (head == tail) {
        head = tail = -1;
    } else {
        head = (head + 1) % capacity;
    }

    return value;
}

// Remove tail
int remove_tail() {
    if(is_empty()) {
        return INT_MIN;
    }

    int value = deque[tail];

    // one element
    if (head == tail) {
        head = tail = -1;
    } else if (tail == 0) {
        // new tail is last element
        tail = capacity - 1;
    } else {
        tail = (tail - 1) % capacity;
    }

    return value;
}

// create
void create_deque(int n) {
    capacity = n;
    deque = (int *) malloc(capacity * sizeof(int));
    head = tail = -1;
}

// sliding window
int* sliding_window(int* nums, int num_size, int k, int *return_size){
    
    // ans
    *return_size = num_size - k + 1;
    int *ans = (int *)malloc((num_size - k + 1) * sizeof(int));

    // deque
    create_deque(k);
    
    for(int i = 0; i < num_size; i++){
        // remove elements that are not in range
        if(!is_empty() && peek_head() <= i - k) 
            remove_head();
 
        // remove smaller elements that are in range 
        while(!is_empty() && nums[peek_tail()] <= nums[i]){
            remove_tail();
        }    
 
        // add current's index
        add_tail(i);
 
        // current window
        if(i + 1 >= k)
            ans[i + 1 - k] = nums[peek_head()];
    }

    free(deque);

    return ans;

}

void main() {
    int n = 0;
    int array[] = {1,3,-1,-3,5,3,6,7};
    int *ans = sliding_window(array, 8, 3, &n); //[3,3,5,5,6,7]
    assert(n == 6);
    assert(ans[0] == 3);
    assert(ans[2] == 5);
    assert(ans[4] == 6);
    assert(ans[3] == 5);
    assert(ans[5] == 7);

    int array2[] = {1,-1};
    ans = sliding_window(array2, 2, 1, &n); //[1,-1]]
    assert(n == 2);
    assert(ans[0] == 1);
    assert(ans[1] == -1);
    
    
    int array3[] = {4,2,5,3,4,2,10,2,11,15};
    ans = sliding_window(array3, 10, 3, &n); //[1,-1]]
    assert(n == 8);
    assert(ans[0] == 5);
    assert(ans[3] == 4);
    assert(ans[4] == 10);
    assert(ans[7] == 15);    
}