#include <bits/stdc++.h>
using namespace std;

struct Job{
	int id;
	int deadline;
	int profit;
};

bool comparison(Job x, Job y) {
     return (x.profit > y.profit);
}
 
void printJob(Job arr[], int n) {
    sort(arr, arr+n, comparison);
 
    int result[n]; 
    bool slot[n];  
 
    for (int i=0; i<n; i++)
        slot[i] = false;
 
    for (int i=0; i<n; i++) {
		for (int j=min(n, arr[i].deadline)-1; j>=0; j--) {
        	if(slot[j]==false) {
            	result[j] = i;  
            	slot[j] = true; 
            	break;
          	}
       	}
    }
 
    for (int i=0; i<n; i++)
        if (slot[i])
        	cout << arr[result[i]].id << " ";

    printf("\n");
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {

		int n, profit = 0;
		scanf("%d",&n);
		Job job[n];
		for(int i = 0; i < n; i ++) {
			job[i].id = i+1;
			scanf("%d %d",&job[i].deadline,&job[i].profit);
		}

		printJob(job, n);
	}

	return 0;
}