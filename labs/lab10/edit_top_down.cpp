#include <bits/stdc++.h>

int edit(int,int);
int min(int,int,int);
int mini(int,int);

char x[30],y[30];
int mem[30][30];

int main() {
	printf("Enter the strings\n");
	scanf("%s%s",x,y);
	int n=strlen(x);
	int m=strlen(y);
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			if(i==0)
				mem[i][j]=j;
			else if(j==0)
				mem[i][j]=i;
			else if(x[i-1]==y[j-1])
				mem[i][j]=mem[i-1][j-1];
			else
				mem[i][j]=(1+min(mem[i-1][j],mem[i][j-1],mem[i-1][j-1]));
		}
	}
	
	printf("the edit distance is: %d\n",mem[n][m]);
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