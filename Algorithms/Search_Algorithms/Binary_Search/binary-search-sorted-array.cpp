#include<iostream>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i = 0 ; i < n ; i ++)
        scanf("%d",&a[i]);

for(int i=0;i<n;i++)
{
for(int j=i+1;j<=n;j++)
{
if(a[i]>a[j])
{
int temp=a[i];
a[i]=a[j];
a[j]=temp;

}
}
}


    int key;
    scanf("%d",&key);

    int first = 0, last = n -1;
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
