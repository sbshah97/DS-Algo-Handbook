#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2, int m, int n) {
	int dp[m+1][n+1];

	for(int i =0; i <= m; i ++) {
		for(int j = 0; j <= n; j ++) {
			//If first string is empty,
			//Minimum j operations in that row
			if(i == 0)
				dp[i][j] = j;

			//If second string is empty,
			//Minimum i operations in that row
			else if(j == 0)
				dp[i][j] = i;

			//If last characters are the same,
			//Go ahead for the rest of the characters
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];

			else 
				dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
		}
	}

	return dp[m][n];
}

int main() {
	string s1, s2;

	cin >> s1;
	cin >> s2;

	printf("%d\n",editDistance(s1, s2, s1.size(), s2.size()));

	return 0;
}