#include<stdio.h>

void swap (int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main() {

	int a,b;
	printf("Enter the numbers to be swapped\n");
	scanf("%d %d",&a,&b);

	printf("Value before swapping");
        printf(" a = %d and b = %d\n",a,b);

	swap(&a, &b);

	printf("Value after swapping");
	printf(" a = %d and b = %d\n",a,b);
}
