#include <stdio.h>

#define 	N 	2000

int oo[1 + (N - 1) * 2], oj[1 + (N - 1) * 2];

int link (int o, int j) {
	static int _ = 1;

	oo[_] = o, oj[_] = j;
	return _++;
}

int ae[N];
int dis;

void dfs (int p, int i, int d) {
	if (d > dis) {
		dis = d;
	}
	int o, j;
	for (o = ae[i]; o; o = oo[o]) {
		j = oj[o];
		if (j != p) {
			dfs (i, j, d + 1);
		}
	}
}

int main () {
	int n, h, i, j;
	scanf("%d", &n);

	for (h = 0; h < n - 1; h++) {
		scanf("%d%d", &i, &j), i--, j--;
		ae[i] = link (ae[i], j);
		ae[j] = link (ae[j], i);
	}

	dis = -1;
	for (i = 0; i < n; i++) {
		dfs (-1, i, 0);
	}

	printf("%d\n", dis);
}