#include <bits/stdc++.h>
using namespace std;

int editDist(string s1, string s2, int m, int n) {
	//If second string is empty
	if(m == 0)
		return n;

	//If first string is empty
	if(n == 0)
		return m;

	if(s1[m-1] == s2[n-1])
		return editDist(s1, s2, m-1, n-1);

	return 1 + min(min(editDist(s1, s2, m, n-1), editDist(s1, s2, m-1, n)), editDist(s1, s2, m-1, n-1));
}

int main(){
	string s1, s2;
	
	cin >> s1;
	cin >> s2;

	printf("%d\n",editDist(s1, s2, s1.size(), s2.size()) );

	return 0;
}