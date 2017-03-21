#include <bits/stdc++.h>
#include <stdlib.h>

#define N 4

struct interval{
	int start;
	int end;
	int wt;
}in[N], order[N];

int prev[N] = {-1,-1,-1,-1};
int m[N] = {-1,-1,-1,-1};

void copy(int i, int j){
	order[j].start=in[i].start;
	order[j].end=in[i].end;
	order[j].wt=in[i].wt;
}

int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}

int opt(int i){
	if(i<0)
		return 0;
	else if(m[i]!=-1)
		return m[i];
	else
		m[i]=max(opt(i-1),order[i].wt+opt(prev[i]));
		return m[i];
}

void print(int n){
	if(n<0)
		return;
	if(n==0){
		printf("%d ",order[0].wt);
		return;
	}
	if(m[n]==m[n-1])
		print(n-1);
	else{
		printf("%d ",order[n].wt);
		print(prev[n]);
	}
}

int main(){
	
	int j,k,i,min=10,last=0;
	
	in[0].start=2; 
	in[0].end=4; 
	in[0].wt=8;

	in[1].start=0; 
	in[1].end=3; 
	in[1].wt=10;

	in[2].start=1; 
	in[2].end=5; 
	in[2].wt=6;

	in[3].start=3; 
	in[3].end=6; 
	in[3].wt=4;

	//Sorting according to finish time
	for(i=0;i<N;i++){
		min=10;
		for(j=0;j<N;j++){
			if(in[j].end < min && in[j].end>last){
				min=in[j].end;
				k=j;
			}
		}
		last=in[k].end;
		copy(k,i);
	}

	//Using Top-Down approach
	//Calculating array prev.
	for(i=0;i<N;i++)
		printf("%d ",order[i].end);
	for(i=N-1;i>=0;i--){
		for(j=i;j>=0;j--){
			if(order[i].start >=order[j].end){
				prev[i]=j;
				break;
			}
		}
	}

	printf("\nPrev Array: ");
	for(i=0;i<N;i++)
		printf("%d ",prev[i]);

	min=opt(N-1);
	printf("\nMax weight of interval %d ",min);
	printf("\nThe weight of interval present in the optimal solution \n");
	print(N-1);

	printf("\n");
	return 0;
}
