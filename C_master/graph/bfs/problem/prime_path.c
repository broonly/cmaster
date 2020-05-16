/* https://www.spoj.com/problems/PPATH/ */
#include <stdio.h> 
#include <math.h>
#include <string.h>

#define 	N 	1000
#define 	M 	10000

int oo[1 + M * 2], oj[1 + M * 2];

int link (int o, int j) {
	static int _ = 1;

	oo[_] = o, oj[_] = j;
	return _++;
}

int ae[M], dis[M], vis[M], np[M], p[M];
int c;

int prime (int n) {
	int i;
	if (n == 0 || n == 1) {
		return 0;
	}
	for (i = 2; i <= sqrt (n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int calc (int n, int m) {
	int cnt = 0;
	while (n) {
		if (n % 10 != m % 10) {
			++cnt;
		}
		n /= 10, m /= 10;
	}
	return cnt;
}

void pre () {
	int i, j;
	c = 0;
	for (i = N; i < M; i++) {
		if (prime (i)) {
			p[c++] = i;	
		}
	}

	for (i = 0; i < c; i++) {
		for (j = i + 1; j < c; j++) {
			int ii = p[i], jj = p[j];
			np[ii] = i;
			if (calc (ii, jj) == 1) {
				ae[i] = link (ae[i], j);
				ae[j] = link (ae[j], i);
			}
		}
	}
}

void reset () {
	memset (vis, 1, sizeof vis);
	memset (dis, 0, sizeof dis);
}

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

int main () {

	pre ();

	int t;
	scanf ("%d", &t);

	while (t--) {
		
		reset ();

		int a, b, i, j;
		scanf ("%d%d", &a, &b);

		bfs(np[a], c);

		printf("%d\n", dis[np[b]]);
	}
}