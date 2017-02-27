#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		//No of deno.
		int n;
		scanf("%d",&n);

		//tYPES OF DENO.
		int arr[n];
		for(int i = 0; i < n; i ++)
			scanf("%d ",&arr[i]);

		//vAL -> Value of total
		int val,count=INT_MAX;
		scanf("%d",&val);

		//Sorting types of deno.
		sort(arr, arr+n);

		for(int j = n-1; j >= 0; j --) {
			int val_temp = val;
			int count_temp = 0;
			int i = j;
			while(i >= 0) {
				if(val_temp >= arr[i]) {
					val_temp -= arr[i];
					count_temp ++;
				}
				else if(val_temp < arr[i]) {
					i --;
				}
			}
			if(count_temp < count)
				count = count_temp;
		}

		printf("%d\n",count);
	}
	return 0;
}