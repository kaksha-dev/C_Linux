/**
 * Sort an array of integers using Insertion Sort, selection sort
 */

#include <stdio.h>

void insertion_sort(int *array, int size) {

    // check if the element is at the correct position
    // else shift elements in sorted part to make space for it
    for (int i = 1; i < size; i++) {
        int current = i;

        while ((current > 0) && (array[current - 1] > array[current])) {
            int temp = array[current];
            array[current] = array[current - 1];
            array[current -1 ] = temp;
            current--;
        }
    }
}

void selection_sort(int *array, int size) {

    // find the index of smallest element in the unsorted part
    // swap it with its correct place in sorted part 
    for (int i = 0; i < size; i++) {
        int minimum = i;

        for (int current = i + 1; current < size; current++) {
            if (array[minimum] > array[current]) {
                minimum = current;
            }
        }

        if (i != minimum) {
            int temp = array[i];
            array[i] = array[minimum];
            array[minimum] = temp;
        }
    }
}

void main() {

    int array[] = {6,3,1,4,2,5};
    insertion_sort(array,6);
    int array2[] = {6,3,1,4,2,5};
    selection_sort(array2,6);   
}