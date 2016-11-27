
#include <bits/stdc++.h>
using namespace std;

long long int binarySearch(long long int arr[], long long int l, long long int r, long long int x) {
        if (r >= l) {
                int mid = l + (r - l)/2;

                if (arr[mid] == x)  
                    return mid;/*if found return the index*/

                if (arr[mid] > x) 
                    return binarySearch(arr, l, mid-1, x);/*search in left subarray*/

                return binarySearch(arr, mid+1, r, x);/*search in right subarray*/
        }

        return -1;/*if not found return index -1*/
}


int main() {
        
        long long int n,t,inarr[100001],i,q,ans;
        scanf("%lld",&n);/*number of input numbers*/
        
        /*input sorted array of size n*/
        for (i=0;i<n;i++) {
            scanf ("%lld",&inarr[i]);
        }

        ans = binarySearch(inarr,0,n-1,5);
        
        /*if non-negative index exists*/
        if (ans!=-1) {
            printf ("Exists\n");
        }
        else 
            printf("Does not Exist\n" );
        
        return 0;
}
