#include <bits/stdc++.h>
using namespace std;

struct interval{
	int start;
	int end;
	int weight;
};

interval intervals[10];
int prev[10];
int memo[10];

void bubble_sort(int n) {
	
	for(int i = 1; i <= n-1; i ++) {
		for(int j = i+1; j <= n; j ++) {
			if(intervals[j].end < intervals[i].end) {
				int temp = intervals[j].end;
				intervals[j].end = intervals[i].end;
				intervals[i].end = temp;
			}

		}
	}

}

void print_intervals(int n) {

	//Print intervals
	for(int i = 1; i <= n; i ++)
		printf("%d %d %d\n",intervals[i].start, intervals[i].end, intervals[i].weight);
	printf("\n");
}

int previous(int n) {
	for(int i = n; i >= 0; i --){
		int j = i - 1;
		
		while(intervals[j].end > intervals[i].start && j>0) {
			j--;
		}
		prev[i] = j;
	}
}

int opt_weight(int i) {
	
	memo[1] = intervals[0].weight;
	for(int i = 2; i <= n; i ++) {
		memo[i] = max(memo[i-1], intervals.weight[i]+prev[memo[i-1]]);
	}
}


int main() {
	
	int n;
	scanf("%d",&n);

	//Input starting, ending and weight of all intervals
	for(int i = 1; i <= n; i ++)
		scanf("%d %d %d",&intervals[i].start, &intervals[i].end, &intervals[i].weight);


	print_intervals(n);

	bubble_sort(n);

	previous(n);

	print_intervals(n);

	int val = opt_weight(n);

	printf("%d\n",val);

	return 0;
}