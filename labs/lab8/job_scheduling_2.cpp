#include <bits/stdc++.h>
using namespace std;

struct job{
	int value;
	int deadline;
	int profit;
};

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {

		int n, profit = 0;
		scanf("%d",&n);
		job job[n];
		for(int i = 0; i < n; i ++) {
			job[i].value = i;
			scanf("%d %d",&job[i].deadline,&job[i].profit);
		}

	}

	return 0;
}