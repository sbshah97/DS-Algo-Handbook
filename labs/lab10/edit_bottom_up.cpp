#include <bits/stdc++.h>

int edit(int,int);
int min(int,int,int);
int mini(int,int);


char x[30],y[30];
int mem[30][30];

int main() {
	printf("enter the strings\n");
	scanf("%s%s",x,y);
	int n=strlen(x);
	int m=strlen(y);
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			mem[i][j]=-1;
		}
	}
	
	int e=edit(n,m);
	printf("the edit distance is: %d\n",e);
	for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
				{
					printf("%d\t",mem[i][j]);
				}
			printf("\n");
		}
	//print(n,m);
}

int edit(int a,int b) {
			
	if(a==0)
			return b;
	if(b==0)
			return a;
	if(x[a-1]==y[b-1]) {
		if(mem[a][b]!=-1)
				return mem[a][b];
		else {
			mem[a][b]=edit(a-1,b-1);
			return mem[a][b];
		}
	}

	else {
		if(mem[a][b]!=-1)
			return mem[a][b];
		else {
			mem[a][b]=(1+min(edit(a,b-1),edit(a-1,b),edit(a-1,b-1)));
			return mem[a][b]; 
		}
	}
}

int min(int a,int b,int c) {
	return mini(a,mini(b,c));
}

int mini(int a,int b) {
	if(a<=b)
			return a;
	else
		return b;
}