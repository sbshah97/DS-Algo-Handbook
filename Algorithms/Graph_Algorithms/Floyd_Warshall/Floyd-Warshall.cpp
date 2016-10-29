#include<bits/stdc++.h>
using namespace std;


int v ;
int graph[50][50];

void FW() {
	int dis[v][v] ;

	for(int i =0;i<v;i++) { //initializing the distance array with input array
		for(int j=0;j<v;j++) {
			dis[i][j] = graph[i][j] ;
		}
	}
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++){
			for (int j = 0; j < v; j++) {
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j] ;
			}
		}
	}
	cout<<"Matrix with shortest distance between every pair i and j.\n";
	for (int i = 0; i < v; i++){
		for (int j = 0; j < v; j++){
			if (dis[i][j] == 9999)
				cout << "INF " ;
			else
				cout << dis[i][j] << "\t" ;
		}
		cout << endl ;
	}


}

int main(int argc, char const *argv[]) {
	cout << "Number of vertices: ";
	cin >> v ; //number of vertices
	cout << "Fill Adjacency List with weight or 9999 if no edge exists.\n";
	for(int i =0;i<v;i++) {
		for(int j=0;j<v;j++) {
			cin >> graph[i][j] ;  //enter 9999 for no edge
		}
	}
	FW() ;
	return 0;
}
