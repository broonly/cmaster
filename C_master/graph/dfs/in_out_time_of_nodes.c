#include <stdio.h>

#define N 	2000

int oo[1 + (N - 1) * 2], oj[1 + (N - 1) * 2];

int link (int o, int j) {
	static int _ = 1;

	oo[_]= o, oj[_] = j;
	return _++;
}

int ae[N], in[N], out[N], pp[N];

void dfs (int p, int i) {
	static int time;
	int o, j;
	pp[i] = p;
	in[i] = time++;
	printf("%d ", i + 1);
	for (o = ae[i]; o; o = oo[o]) {
		j = oj[o];
		if (j != p) {
			dfs (i, j);
		}
	}
	out[i] = time;

}
int main () {
	int n, h, i, j;
	scanf("%d", &n);

	for (h = 0; h < n - 1; h++) {
		scanf("%d%d", &i, &j), i--, j--;
		ae[i] = link (ae[i], j);
		ae[j] = link (ae[j], i);
	}

	dfs (-1, 0);

	printf("\nNode   in    out\n");
	for (i = 0; i < n; i++) {
		printf("%d\t%d\t%d\n", i + 1, in[i], out[i]);
	}
}