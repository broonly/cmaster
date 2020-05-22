#include <stdio.h>

#define 	N 	100000

int a[N], subset[N];
int c;

void search (int i, int n) {
	static int f = 1;
	if (i == n) {
		int j;
		printf("%d -> ", f++);
		for (j = 0; j < c; j++) {
			printf("%d ", subset[j]);
		}
		printf("\n");
	}
	else {
		//include the current index and then search for the next too
		subset[c++] = a[i];
		search (i + 1, n);
		//don't include the current index and search for the next index
		c--;
		search (i + 1, n);
	}

}

int main () {
	
	int n, i;
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
	}

	printf("here are all the subsets\n");
	c = 0;
	search (0, n);

	return 0;
}