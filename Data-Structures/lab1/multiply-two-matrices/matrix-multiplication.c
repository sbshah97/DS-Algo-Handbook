#include<stdio.h>
int  main() {
	//Variable Declaration
	int i,j,k;
	int r1,c1,r2,c2;
	printf("Enter the rows and columns in the first matrix\n");
	scanf("%d %d",&c1,&r1);
	printf("Enter the rows and columns in the second matrix\n");
	scanf("%d %d",&c2,&r2);	
	int a[c1][r1],b[c2][r2], c[c1][r2]; 
	
	//Matrix Multiplication condition
	if(r1 == c2) {

	    //Input for first matrix
	    printf("Enter the elements in the first matrix\n");
		for(i = 0 ; i < c1 ; i ++)
			for(j = 0 ; j < r1 ; j ++)
			    scanf("%d", &a[i][j]);

		//Input for second matrix
		printf("Enter the elements in the second matrix\n");
		for(i = 0 ; i < c2 ; i ++)
			for(j = 0 ; j < r2 ; j ++)
			    scanf("%d", &b[i][j]);
	    
	    //Initialise result array
	    for(i = 0 ; i < c1 ; i ++)
			for(j = 0 ; j < r2 ; j ++)
			    c[i][j] = 0;

		//Matrix Multiplication Algorithm
        	for(i = 0 ; i < c1 ; i ++)
			for(j = 0 ; j < r2 ; j ++)
			    for(k = 0 ; k < r1 ; k ++ )
			        c[i][j] += a[i][k]*b[k][j];
		
		//Output result array	        
        for(i = 0 ; i < c1 ; i ++) {
			for(j = 0 ; j < r2 ; j ++) {
			    printf("%d ",c[i][j]);
			}
			printf("\n");
        }
        
	}

	else 
	     printf("Matrix multiplication not possible\n");

}
