/**
 * @Author shrawnz
 * @date   24 October, 2016
 */

#include <iostream>
using namespace std;

int main()
{
	int n,temp,i,j;
	cout<<"Enter number of elements: \n";
	cin>>n;

	int arr[n];

	cout<<"Enter elements: \n";

	for(i=0;i<n;i++)
		cin>>arr[i];

	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	cout<<"Array after sorting: \n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";

return(0);
}