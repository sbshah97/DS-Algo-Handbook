#include <bits/stdc++.h>

using namespace std;

struct Point{
	int x, y;
};

double distance(int x1, int x2, int y1, int y2) {
	double x, y;
	x = (x1 - x2)*(x1 - x2);
	y = (y1 - y2)*(y1 - y2);
	return sqrt(x + y);
} 

double bruteForce(Point P[], int n) {

	double min = 9999999;
	double dist;
	
	for(int i = 0; i < n - 1; i ++) {
		for(int j = i + 1; j < n; j ++) {
			dist = distance(P[i].x, P[j].x, P[i].y, P[j].y);
			//printf("%f %f\n",dist, min );
			if(dist < min) 
				min = dist;
		}
	}

	return min;
}

int main() {
	int n;
	printf("Enter number of points\n->");
	scanf("%d",&n);

	int x, y;

	Point P[10];

	for(int i = 0; i < n; i ++) {
		scanf("%d %d",&x,&y);
		P[i].x = x;
		P[i].y = y;
	}

	printf("The closest distance between two points is %f\n",bruteForce(P, n));

	// for(int i = 0; i < n; i ++) {
	// 	printf("%d %d\n",P[i].x,P[i].y);
	// }

	return 0;
}