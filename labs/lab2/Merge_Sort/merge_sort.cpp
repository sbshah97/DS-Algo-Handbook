#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

void merge(int low, int mid, int high) {
	int i, j, k;

	for(i = low, j = low, k = mid+1; j <= mid && k <= high; i++, j++) {
		if(a[j] <= a[k])
			b.push_back(a[j++]);
		else
			b.push_back(a[k++]);
	}

	while(j <= mid)
		b.push_back(a[j++]);

	while(k <= mid)
		b.push_back(a[k++]);

	a.clear();
	for(i = low; i <= high; i ++)
		a[i] = b[i];
}

void mergeSort(int low, int high) {
	int mid;

	if(low < high) {
		mergeSort(low, mid);
		mergeSort(mid+1, high);
		merge(low, mid, high);
	}	

	else 
		return;
}

int main() {
	int n, temp;
	scanf("%d",&n);

	for(int i = 0; i < n; i ++) {
		scanf("%d",&temp);
		a.push_back(temp);
	}

	mergeSort(0, n-1);

	for(int i = 0; i < n; i ++) 
		printf("%d ",a[i] );

	return 0;
}