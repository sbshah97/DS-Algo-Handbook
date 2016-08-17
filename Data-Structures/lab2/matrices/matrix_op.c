#include<stdio.h>

int main() {

	//Variable declaration
	int r1,c1,i,j;
	printf("Enter the number of rows and columns in");
	printf("the first matrix and second matrix");
	scanf("%d %d",&r1,&c1);

	int a[r1][c1],b[r1][c1],c[r1][c1];

	//Input for matrix 1
	for(i = 0 ; i < r1; i ++)
		for(j = 0 ; j < c1 ;j ++)
			scanf("%d",&a[i][j]);
	printf("\n");

	//INput for matrix 2
	for(i = 0 ; i < r1; i ++)
                for(j = 0 ; j < c1 ;j ++)
                        scanf("%d",&b[i][j]);
	printf("\n");

	//Addition of two matrices
	for(i = 0 ; i < r1; i ++) {
                for(j = 0 ; j < c1 ;j ++){
                        c[i][j] = a[i][j] + b[i][j];
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//Subtraction of two matrices
	for(i = 0 ; i < r1; i ++) {
                for(j = 0 ; j < c1 ;j ++){ 
                        c[i][j] = a[i][j] - b[i][j];
                        printf("%d ",c[i][j]);
                }
                printf("\n");
        }
	printf("\n");

	//Array initialisation
	int d[c1][r1];

	//Transpose of first matrix
	for(i = 0 ; i < c1; i ++) {
                for(j = 0 ; j < r1 ;j ++){ 
			d[i][j] = a[j][i];
			printf("%d ",d[i][j]);
                }
                printf("\n");
        }
	printf("\n");

	//Searching an element
	int key;
	printf("Enter the element you wan to search\n");
	scanf("%d",&key);
	printf("\n");

	//Search algorithm
	for(i = 0 ; i < r1; i ++) {
                for(j = 0 ; j < c1 ;j ++){ 
                        if(key == a[i][j])
                        	printf("\nKey found in row %d and column %d\n",i+1,j+1);
                }
        }

	return 0;
}
