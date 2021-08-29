#include <stdio.h>


void tower_of_hanoi(int n, char from, char to, char aux){
	if (n==1){
		printf("%c to %c\n",from,to);
		return;
	}
	tower_of_hanoi(n-1, from, aux, to);
	printf("%c to %c\n",from,to);
	tower_of_hanoi(n-1, aux, to, from);
}
int main(){
	tower_of_hanoi(4, 'A', 'B' , 'C');

}

