#include <iostream>
#include "Quicksort.h"
using namespace std;
 
 
void print(int arr[], int n) {
    for (int i = 0; i <n; i++) 
    cout << arr[i] << "-";
    
    cout << endl;
}
 
int main (){
    int n;
    
    int i;
    
    cout<<"Array Size: ";
    cin>> n;
    cout<<endl;
    
    int* arr=new int [n];
    
    for (i=0;i<n;i++) {
        cout << "Array[" << i+1 << "]: ";
        cin >>  arr[i];
        cout<<endl;
    }

    print(arr,n);
    
    quickSort(arr, 0, n-1);
    
    print(arr,n);
 
}