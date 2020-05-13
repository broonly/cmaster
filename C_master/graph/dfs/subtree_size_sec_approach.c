#include <stdio.h>
#include <string.h>

#define 	N 	20000

int oo[1 + (N - 1) * 2], oj[1 + (N - 1) * 2];

int link (int o, int j) {
	static int _ = 1;

	oo[_] = o, oj[_] = j;
	return _++;
}

int ae[N], size[N];

void dfs (int p, int i) {
	int o, j;
	for (o = ae[i]; o; o = oo[o]) {
		j = oj[o];
		if (j != p) {
			dfs (i, j);
			size[i] += size[j];
		}
	}
}

int main () {
	int n, i, j, h;
	scanf ("%d", &n);

	for (h = 0; h < n - 1; h++) {
		scanf ("%d%d", &i, &j), i--, j--;
		ae[i] = link (ae[i], j);
		ae[j] = link (ae[j], i);
	}
	
	for (i = 0; i < n; i++) {
		size[i] = 1;
	}
	
	dfs (-1, 0);

	

	printf ("node   size\n");
	for (i = 0; i < n; i++) {
		printf(" %d\t%d\n", i + 1, size[i]);
	}
	
}