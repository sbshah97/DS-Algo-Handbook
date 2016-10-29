#include  <iostream>
using namespace std;

// function to sort a using shellSort
int shellSort(int a[],int n)
{
	for(int shell=n/2;shell>0; shell/=2)
	{
		for(int i=shell;i<n;i++)
		{
			int tmp=a[i];
			int j;            
			for (j=i;(j>=shell) && (a[j-shell]>tmp); j-=shell)
				a[j]=a[j-shell];
			a[j]=tmp;
		}
	}
	return 0;
}
int main()
{
	int n,arr[10000];
	cin >> n;
	for (int i=0;i<n;i++)
		cin >> arr[i];
	shellSort(arr,n);
	cout << "Array after sorting: \n";
	for (int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
