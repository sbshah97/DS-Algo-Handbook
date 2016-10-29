/* bellman-ford.c57.  C57 code to run the Bellman-Ford algorithm on a
   small directed graph. */

#include <stdio.h>

/* Relax edge (u,v) with weight w. */
void relax(int u, int v, double w, double d[], int pi[]) {
  if (d[v] > d[u] + w) {
    d[v] = d[u] + w;
    pi[v] = u;
  }
}

/* Initialize a single-source shortest-paths computation. */
void initialize_single_source(double d[], int pi[], int s, int n) {
  int i;
  for (i = 1; i <= n; ++i) {
    d[i] = 1000000000.0;
    pi[i] = 0;
  }

  d[s] = 0.0;
}

/* Run the Bellman-Ford algorithm from vertex s.  Fills in arrays d
   and pi. */
int bellman_ford(int first[], int node[], int next[], double w[], double d[],
		 int pi[], int s, int n) {
  int u, v, i, j;

  initialize_single_source(d, pi, s, n);

  for (i = 1; i <= n-1; ++i) {
    for (u = 1; u <= n; ++u) {
      j = first[u];

      while (j > 0) {
	v = node[j];
	relax(u, v, w[j], d, pi);
	j = next[j];
      }
    }
  }

  for (u = 1; u <= n; ++u) {
    j = first[u];

    while (j > 0) {
      v = node[j];
      if (d[v] > d[u] + w[j])
	return 0;
      j = next[j];
    }
  }

  return 1;
}

int main(void) {
  int first[6], node[11], next[11], pi[6];
  double w[11], d[6];
  int s;
  int i;
  int ok;

  /* The graph contains the following directed edges with weights:
     (1, 2), weight 6
     (1, 4), weight 7
     (2, 3), weight 5
     (2, 4), weight 8
     (2, 5), weight -4
     (3, 2), weight -2
     (4, 3), weight -3
     (4, 5), weight 9
     (5, 1), weight 2
     (5, 3), weight 7
  */

  first[1] = 1;
  first[2] = 3;
  first[3] = 6;
  first[4] = 7;
  first[5] = 9;

  node[1] = 2;
  node[2] = 4;
  node[3] = 3;
  node[4] = 4;
  node[5] = 5;
  node[6] = 2;
  node[7] = 3;
  node[8] = 5;
  node[9] = 1;
  node[10] = 3;

  w[1] = 6.0;
  w[2] = 7.0;
  w[3] = 5.0;
  w[4] = 8.0;
  w[5] = -4.0;
  w[6] = -2.0;
  w[7] = -3.0;
  w[8] = 9.0;
  w[9] = 2.0;
  w[10] = 7.0;

  next[1] = 2;
  next[2] = 0;
  next[3] = 4;
  next[4] = 5;
  next[5] = 0;
  next[6] = 0;
  next[7] = 8;
  next[8] = 0;
  next[9] = 10;
  next[10] = 0;

  printf("Enter source node: ");
  scanf("%d", &s);

  ok = bellman_ford(first, node, next, w, d, pi, s, 5);

  printf("bellman_ford returns ");
  printf("%d\n\n", ok);

  for (i = 1; i <= 5; ++i) {
    printf("%d: %f  %d\n", i, d[i], pi[i]);
  }

  return 0;
}

/* Correct outputs:

   Enter source node: 1
   bellman_ford returns 1

   1: 0.000000  0
   2: 2.000000  3
   3: 4.000000  4
   4: 7.000000  1
   5: -2.000000  2

   Enter source node: 2
   bellman_ford returns 1

   1: -2.000000  5
   2: 0.000000  0
   3: 2.000000  4
   4: 5.000000  1
   5: -4.000000  2

   Enter source node: 3
   bellman_ford returns 1

   1: -4.000000  5
   2: -2.000000  3
   3: 0.000000  0
   4: 3.000000  1
   5: -6.000000  2

   Enter source node: 4
   bellman_ford returns 1

   1: -7.000000  5
   2: -5.000000  3
   3: -3.000000  4
   4: 0.000000  0
   5: -9.000000  2

   Enter source node: 5
   bellman_ford returns 1

   1: 2.000000  5
   2: 4.000000  3
   3: 6.000000  4
   4: 9.000000  1
   5: 0.000000  0
*/