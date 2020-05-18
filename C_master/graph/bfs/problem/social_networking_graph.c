/* https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/ */
#include <stdio.h>
#include <string.h>

#define 	N 	10000

int oo[1 + N * 2], oj[1 + N * 2];

int link (int o, int j) {
	static int _ = 1;

	oo[_] = o, oj[_] = j;
	return _++;
}

int ae[N], vis[N], dis[N];

int bfs (int i, int n, int d) {
	static int q[N];
	int c, o, j, top, s, f;

	c = top = s = f = 0, q[c++] = i, vis[i] = 0;
	while (c != n) {
		i = q[top];
		for (o = ae[i]; o; o = oo[o]) {
			j = oj[o];
			if (vis[j]) {
				q[c++] = j, vis[j] = 0, dis[j] = dis[i] + 1;
				if (dis[j] == d) {
					s++;
				}
				else if (dis[j] > d) {
					f = 1;
					break;
				}
			}
		}
		if (f) {
			break;
		}
		top++;
	}
	return s;
}

void reset () {
	memset (vis, 1, sizeof vis);
	memset (dis, 0, sizeof dis);
}

int main () {
	int n, e, m, h, i, j, sc, t, s;
	scanf ("%d%d", &n, &e);

	while (e--) {
		scanf ("%d%d", &i, &j);
		//i--, j--;
		ae[i] = link (ae[i], j);
		ae[j] = link (ae[j], i);
	}

	scanf ("%d", &m);

	while (m--) {

		reset ();

		scanf ("%d%d", &sc, &t);

	//	sc--;
		s = bfs (sc, n, t);
		printf("%d\n", s);
	}
}