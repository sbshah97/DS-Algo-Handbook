#include <iostream>
using namespace std;
int main()
{
int Key;
int n;
cout<<"Enter array size:"<<endl;
cin>>n;
int array[n];

cout<<"Enter "<<n<< " numbers: "<<endl;
for(int i=0; i<n; i++) 
{ 
cin>>array[i];
}
cout<<endl;
cout<<"Originally entered array by the user is: "<<endl;
for(int j=0; j<n; j++)
{
cout<<array[j];
cout<<endl;
}
cout<<endl;
for(int j=1 ; j < n ; j++) 
{ Key = array[j]; 
int i = j-1; 
while(i >= 0 && array[i] > Key)
{
array[i + 1] = array[i];
i = i - 1;
}
array[i + 1] = Key;
}
cout<<"Sorted Array is: "<<endl;
for(int i=0; i<n; i++)
{
cout<<array[i]<<endl;
}


}