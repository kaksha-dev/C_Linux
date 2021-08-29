#include <stdio.h>
// every third no of fibonacci series - or print even numbers in fibonacci series
int main(){

	int i = 2;
	int j = 8;
	int k = 0;
	for(k = 0;k<10;k++){
            printf("%d\n", i);
	    int temp = i;
	    i = j;
	    j = 4*j + temp;

	}
}
