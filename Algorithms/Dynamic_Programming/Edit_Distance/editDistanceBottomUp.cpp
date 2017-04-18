#include <bits/stdc++.h>
using namespace std;

int mem[30][30];

int editDistance(string s1, string s2, int a, int b) {
	if(a == 0)
		return b;

	if(b == 0)
		return a;

	if(s1[a-1] == s2[b-1]) {
		if(mem[a][b] != -1)
			return mem[a][b];
		else {
			mem[a][b] = editDistance(s1, s2, a-1, b-1);
			return mem[a][b];
		}
	}

	else {
		if(mem[a][b] != -1)
			return mem[a][b];
		else {
			mem[a][b] = (1+ min(min(editDistance(s1, s2, a, b-1), editDistance(s1, s2, a-1, b)), editDistance(s1, s2, a-1, b-1)));
			return mem[a][b];
		}
	}
}

int main() {
	string s1, s2;

	cin >> s1;
	cin >> s2;

	for(int i = 0; i <= s1.size(); i ++) {
		for(int j = 0; j <= s2.size(); j++) {
			mem[i][j] = -1;
		}
	}

	printf("%d\n",editDistance(s1, s2, s1.size(), s2.size()));

	return 0;
}