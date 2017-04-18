//Bottom Up Approach for Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

int arr[10]; 
int l[10];

int biggerElements(int i, int n){
	int count = 1;
	for(int j = i; j < n; j ++) {
		if(arr[j+1] > arr[j]) {
			count++;	
		}
	}

	return count;
}

int main() {

	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i ++) {
		scanf("%d",&arr[i]);
		//Every element is the longest 
		//subsequence of its own self
		l[i] = 1;
	}

	for(int i = n-2; i >= 0; i --) 
		l[i] = max(l[i+1], biggerElements(i, n));

	sort(l, l+n);

	printf("Length of the Longest Subsequence is %d\n",l[n-1]);

	return 0;
}