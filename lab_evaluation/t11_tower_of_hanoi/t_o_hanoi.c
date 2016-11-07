#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char begPeg, char endPeg, char auxPeg) {
	
	if(n==1){ 
		printf("Disc 1 moved from %c to %c \n",begPeg,endPeg);
		return;
	}

	
	hanoi(n-1,begPeg,auxPeg,endPeg);
	printf("Disc %d moved from %c to %c \n",n,begPeg,endPeg);
	hanoi(n-1,auxPeg,endPeg,begPeg);

}

int main() {
	int n;
	char X, Y, Z;

	printf("Enter the number of discs\n");
	scanf("%d",&n);
	printf("\n");
	hanoi(n,'A','B','C');
	return 0;
}