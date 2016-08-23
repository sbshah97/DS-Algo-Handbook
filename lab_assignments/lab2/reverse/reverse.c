#include<stdio.h>
int main() {
	int n,n2;
	int *temp;
	int rem;
	int rev;

	printf("Enter the number to be reversed\n");
	scanf("%d",&n);

	n2 = n;
	temp = &n;
	rev = 0;

	while(*temp > 0) {
		rem = *temp%10 ;
		*temp = *temp / 10;
		rev = ((rev) * 10 + rem);
	}

	n = rev;
	printf("Value of number %d after reversal is %d\n",n2,n);

	return 0;
}
