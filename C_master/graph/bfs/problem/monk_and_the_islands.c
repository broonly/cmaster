/* https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/ */
#include <stdio.h>
#include <string.h>

#define 	N 	10000
#define 	M 	100000

int oo[1 + M * 2], oj[1 + M * 2];
int _;

int link (int o, int j) {

	oo[_] = o, oj[_] = j;
	return _++;
}

int ae[N], vis[N], dis[N];

void bfs (int i, int n) {
	static int q[N];
	int c, o, j, top;

	c = top = 0, q[c++] = i, vis[i] = 0;
	while (c != n) {
		i = q[top];
		for (o = ae[i]; o; o = oo[o]) {
			j = oj[o];
			if (vis[j]) {
				q[c++]= j, vis[j] = 0, dis[j] = dis[i] + 1;
			}
		}
		top++;
	}
}

void reset () {
	memset (vis, 1, sizeof vis);
	memset (dis, 0, sizeof dis);
	memset (ae, 0, sizeof ae);
	_ = 1;
}

int main () {
	int t;
	scanf ("%d", &t);

	while (t--) {

		int n, m, i, j, h ;
		scanf ("%d%d", &n, &m);

		reset ();

		while (m--) {
			scanf ("%d%d", &i, &j), i--, j--;
			ae[i] = link (ae[i], j);
			ae[j] = link (ae[j], i);
		}

		bfs (0, n);
		printf("%d\n", dis[n - 1]);
		
	}
}