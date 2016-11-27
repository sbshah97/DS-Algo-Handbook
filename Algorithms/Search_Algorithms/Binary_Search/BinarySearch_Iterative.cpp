#include <iostream>
using namespace std;

void bubble_sort(int a[], int n) {
    for(int i = 0 ; i < n ; i ++) {
        for(int j = i + 1 ; j <= n ; j ++) {
            if(a[i] > a[j]) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            }
        }
    }
}

void binary_search(int a[], int first, int last, int key) {
    int mid = (first+last)/2;

    while(last > first) {

        if(a[mid] == key) {
            printf("Key found at %d.\n",mid + 1);
            break;
        }

        else if(a[mid] > key)
            last = mid - 1;

        else
            first = mid + 1;
    }
}

int main() {
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i = 0 ; i < n ; i ++)
        scanf("%d",&a[i]);

    int first = 0, last = n -1;

    bubble_sort(a, n);

    int key;
    scanf("%d",&key);

    binary_search(arr,first,last,key);

    return 0;
}
