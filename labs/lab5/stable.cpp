#include <bits/stdc++.h>

using namespace std;

int m[1000],w[1000],mar[2000][1000],n;

int pref(int j,int a,int b) {	
	for(int q=0;q<n;q++) {
		if(mar[j][q]==a)
			return 0;
		if(mar[j][q]==b)
			return 1;
	}
}

void stable() {	
	int i,x;
	while(1) {
		for(i=0;i<n;i++)
			if(m[i]==0)
				break;
		
		if(i>=n)
			return;
		
		else{	
			int j;
			for(j=0;j<n;j++){	
				if(mar[i][j]!=-1 && w[mar[i][j]]==-1){	
					m[i]=mar[i][j];
					w[mar[i][j]]=i;
					mar[i][j]=-1;
					break;
				}
				else {
					x=pref(mar[i][j],w[mar[i][j]],i);
					
					if(x==1) {	
						m[w[mar[i][j]]]=0;
						w[mar[i][j]]=i;
						m[i]=mar[i][j];
						
						break;
					}
					else {	
						mar[i][j]=-1;
						continue;
					}

				}
			}
		}
	}
}

int main() {
	
	cout<<"Enter value of n:\n->";
	cin>>n;
	
	cout<<"Enter stable marriage matrix:\n";
	for(int i=0; i<2*n; i++)
		for(int j=0; j<n; j++)
			cin >> mar[i][j];
	
	for(int i=0;i<2*n;i++)
		w[i] = -1;

	stable();
	
	for(int i=0;i<n;i++)
		cout << i << " -> " << m[i] << endl;
	
	return 0;
}
