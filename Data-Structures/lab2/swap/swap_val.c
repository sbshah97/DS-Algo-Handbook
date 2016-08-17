#include<stdio.h>

//Swap function
void swap (int a, int b) {
	//Declaring temporary variable
	int temp;

	//Swap algorithm
	temp = a;
	a = b;
	b = temp;

	printf("\nNumbers after swapping are");
	printf(" a = %d and b = %d\n",a,b);
}

int main() {
	int a, b;

	printf("Enter the two numbers to be swapped\n");
	scanf("%d %d",&a,&b);

	printf("\nNumbers before swapping are");
	printf(" a = %d and b = %d",a,b);
	swap(a,b);

	return 0;

}
