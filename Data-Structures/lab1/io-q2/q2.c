#include<stdio.h>

int main() {
    
    //Variable declaration
    int a = 5;
    int *b;
    int **c;
    b = &a;
    c = &b;
    
    //Print commands
    printf("%d\n",a);
    printf("%d\n",*(&a));
    printf("%d\n",*b);
    printf("%d\n",**c);
    printf("%d\n",*c);
    printf("%u\n",&a);
    printf("%d\n",b);
    printf("%u\n",&b);
    printf("%d\n",c);
    printf("%u\n",&c);
    
	return 0;
}
