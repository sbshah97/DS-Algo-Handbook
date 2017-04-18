#include <bits/stdc++.h>
using namespace std;

int l[20], arr[20];

int biggerElement(int i, int n) {
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
		l[i] = 1;
	}

	for(int i = n-2; i >= 0; i --) {
		l[i] = max(l[i+1], biggerElement(i, n));
	}

	sort(l, l+n);

	printf("%d\n",l[n-1]);

	return 0;
}