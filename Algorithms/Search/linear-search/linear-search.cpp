#include<iostream>
using namespace std;

int main() {

    //Declaring length of initial array
    int n;
    scanf("%d",&n);

    //INputting elements of the array
    int a[n];
    for(int i = 0 ; i < n ; i ++)
        scanf("%d",&a[i]);

    //INputting the element to be searched in the array
    int key;
    scanf("%d",&key);

    //Using algorithm to find the position of the array
    for(int i = 0 ; i < n ; i ++)
        if( a[i] == key)
            printf("Key found at position %d \n",i + 1);

    return 0;
}
