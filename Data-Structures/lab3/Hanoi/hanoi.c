#include<stdio.h>
void hanoi (int n, char fromrod, char torod, char auxrod) {

	//Base recursion case
	if(n == 1) {
		printf("\nDisk 1 is MOVED from %c to %c",fromrod,torod);
		return;
	}

	//Logic for Hanoi recursion
	hanoi(n-1, fromrod, auxrod, torod);
	printf("\nDisk %d is MOVED from %c to %c",n,fromrod,torod);
	hanoi(n-1, auxrod, fromrod, torod);

}

int main() {

	//Variable declaration
	int n;
	printf("Enter the number of disks : ");
	scanf("%d",&n);

	//Function calling
	hanoi(n, 'X', 'Z', 'Y');
	printf("\n");
	return 0;

}
