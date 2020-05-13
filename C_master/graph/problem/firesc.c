/* https://www.codechef.com/problems/FIRESC */
#include <stdio.h>
#include <string.h>

#define N 	100000
#define mod 	1000000007

int oo[1 + N * 2], oj[1 + N * 2];
int _;

int link (int o, int j) {

	oo[_] = o, oj[_] = j;
	return _++;
}

int ae[N], vis[N];
long long c;

void dfs (int i) {
	int o, j;
	vis[i] = 0;
	c++;
	for (o = ae[i]; o; o = oo[o]) {
		j = oj[o];
		if (vis[j]) {
			dfs(j);
		}
	}
}

void reset () {
	memset (vis, 1, sizeof vis);
	memset (ae, 0, sizeof ae);
	_ = 1;
}

int main () {
	int t, n, m, i, j, h, cc;
	long long s;
	scanf ("%d", &t);

	while (t--) {
	    
	    reset ();

		scanf("%d%d", &n, &m);
		for (h = 0; h < m; h++) {
			scanf ("%d%d", &i, &j), i--, j--;
			ae[i] = link (ae[i], j);
			ae[j] = link (ae[j], i);
		}
		
		cc = 0;
		s = 1, c = 0;
		for (i = 0; i < n; i++) {
			if (vis[i]) {
				++cc;
				c = 0;
				dfs (i);
				s = (s * c) % mod;
			}
		}
		
		printf ("%d %lld\n", cc, s);
		
	}
}