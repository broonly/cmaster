#include <stdio.h>

#define 	N 	100

int col[N], diag1[N], diag2[N];
int cnt;
/*
  numbering the arrays to keep track of columns and two diagonals

	 col	   diag1(/)	   diag2(\)
 | 0 1 2 3 | | 0 1 2 3 | | 3 4 5 6 |
 | 0 1 2 3 | | 1 2 3 4 | | 2 3 4 5 |
 | 0 1 2 3 | | 2 3 4 5 | | 1 2 3 4 |
 | 0 1 2 3 | | 3 4 5 6 | | 0 1 2 3 |

*/
void search (int y, int n) {
	int x;
	if (y == n) {
		cnt++;
	}
	else {
		for (x = 0; x < n; x++) {
			if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
			col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
			
			search (y + 1, n);
			
			col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
		}
	}
}

int main () {
	
	int n;
	scanf ("%d", &n);

	cnt = 0;
	search (0, n);

	printf("%d\n", cnt);

	return 0;
}