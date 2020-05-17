/* https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/ */
#include <stdio.h>
#include <string.h>
 
#define 	N 	1000000
 
int oo[1 + N * 10], oj[1 + N * 10];
int _;
 
int link (int o, int j) {
 
	oo[_] = o, oj[_] = j;
	return _++;
}
 
int ae[N], vis[N], ct[N];
 
void reset () {
	memset (ae, 0, sizeof ae);
	memset (vis, 1, sizeof vis);
	memset (ct, 0, sizeof ct);
	_ = 1;
}
 
int dfs (int i, int cc) {
	int o, j;
	vis[i] = 0;
	ct[i] = cc;
	for (o = ae[i]; o; o = oo[o]) {
		j = oj[o];
		if (vis[j]) {
			dfs (j, cc);
		}
	}
}
 
int main () {
	int t;
	scanf ("%d", &t);
 
	while (t--) {
		
		reset ();
 
 		static int ii[N], jj[N];
		int n, k, h, i, j, c, f, cc, a, b;
		char s[5];
 
		scanf ("%d%d", &n, &k);
 
		c = 0;
		while (k--) {
			scanf ("%d %s %d", &i, s, &j), i--, j--;
			if (s[0] == '=') {
				ae[i] = link (ae[i], j);
				ae[j] = link (ae[j], i);
			}
			else {
				ii[c] = i, jj[c] = j, c++;
			}
		}
 	
		cc = 1;
 		for (i = 0; i < n; i++) {
 			if (vis[i]) {
 				dfs (i, cc);
 				cc++;
 			}
 		}

 		f = 1;
 		for (i = 0; i < c; i++) {
 			a = ii[i], b = jj[i];
 			if (ct[a] == ct[b] && ct[a] != 0) {
 				f = 0;
 				break;
 			}
 		}

 		puts (f ? "YES" : "NO" );
	} 
}