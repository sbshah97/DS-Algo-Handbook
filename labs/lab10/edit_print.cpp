#include <bits/stdc++.h>

int find(int,int,int);
void print(int,int);
int min(int ,int,int);
int mini(int,int);

char x[30],y[30];
int mem[100][100];
char edit[100][100];
int m,n;

int main() {
	printf("enter the two strings\n");
	scanf("%s%s",x,y);
	m=strlen(x);
	n=strlen(y);
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			if(i==0){
				mem[i][j]=j;
				edit[i][j] = 'I';
			}
			else if(j==0){
				mem[i][j]=i;
				edit[i][j] = 'D';
			}
			else if(x[i-1]==y[j-1]){
				mem[i][j]=mem[i-1][j-1];
				edit[i][j] = 'X';
			}
			else {
				mem[i][j]= 1 + min(mem[i-1][j],mem[i][j-1],mem[i-1][j-1]);
				if(mem[i][j] == 1+mem[i-1][j])
					edit[i][j] = 'D';
				else if(mem[i][j] == 1+mem[i][j-1])
					edit[i][j] = 'I';
				else if(mem[i][j] == 1+mem[i-1][j-1])
					edit[i][j] = 'S';
			}
		}
	}
		
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			printf("%d-%c\t",mem[i][j], edit[i][j]);
		}
		printf("\n");
	}
		
	printf("the edit distance is: %d\n",mem[m][n]);
	print(0,0);

	int i=n, j=m;
	char path[100];
	char pn = 0;
	
	while(i>=0 && j>=0){
			if(edit[i][j]=='I'){
				path[pn++] = 'I';
				j--;
			}
			else if(edit[i][j]=='D'){
				path[pn++] = 'D';
				i--;
			}
			else{
				path[pn++] = edit[i][j];
				i--; j--;
			}
	}
	
	path[pn] = 0;
	int ii=0, ij=0;
	
	for(int i=pn-2; i>=0; i--){
		if(path[i]=='I'){
			printf("_ %c 1\n", y[ij]);
			ij++;
		}
		else if(path[i]=='D'){
			printf("%c _ 1\n", x[ii]);
			ii++;
		}
		else {
			printf("%c %c ", x[ii], y[ij]);
			if(path[i]=='S')
				printf("1\n");
			else
				printf("0\n");
			ii++; ij++;
		}
	}
}
		
		

int min(int a,int b,int c) {
	return mini(a,mini(b,c));
}

int mini(int a,int b) {
	if(a>b)
		return b;
	else 
		return a;
}

void print(int i,int j) {
	// while(i>m && j>n)
	// 	return;
	// if(res==1){
	// 	int res=find(mem[i+1][j+1],mem[i+1][j],mem[i][j+1]);
	// 	if(res==1) {
	// 		if(x[i-1]==y[j-1]) {
	// 			printf("%c %c 0\n",x[i-1],y[j-1]);
	// 			print(i+1,j+1);
	// 		}
	// 		else{
	// 			printf("%c %c 1\n",x[i-1],y[j-1]);
	// 			print(i+1,j+1);
	// 		}
	// 	}
	// 	else if(res==2) {
	// 		printf("_ %c 1\n",y[j-1]);
	// 		print(i,j+1);
	// 	}
	// 	else if(res==3) {
	// 		printf("%c _ 1\n",x[i-1]);
	// 		print(i+1,j);
	// 	}
	// }
}	

int find(int a,int b,int c) {
	if(a>=b) {
		if(a>=c)
			return 1;
		else
			return 3;
	}
	else {
		if(b>=c)
			return 2;
		else
			return 3;
	}
}