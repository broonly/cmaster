#include <stdio.h>

#define 	N 	10

int a[N], used[N], permutation[N];
int c;

void search (int n) {
	static int j = 1;
	int i;
	if (c == n) {
		printf("%d -> ", j++);
		for (i = 0; i < n; i++) {
			printf("%d ", permutation[i]);
		}
		printf("\n");
	}
	else {
		for (i = 0; i < n; i++) {
			if (used[i]) continue;
			//let's use the current element for now and search for the next
			used[i] = 1;
			permutation[c++] = a[i];
			search (n);
			//don't take the current element and search for the next
			used[i] = 0;
			c--;
		}
	}
}

int main () {
	
	int n, i;
	scanf ("%d", &n);

	for (i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
	}

	printf("here are all the permutation of the array\n");

	c = 0;
	search (n);

	return 0;
}