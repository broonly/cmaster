#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){

	int n, i, j, k;
	scanf("%d", &n);

	//allocation of one dimentional int array
	int *a1;
	a1 = (int *) malloc(n * sizeof(int));

	//allocation of two dimentional int array

	int row, column;
	scanf("%d%d", &row, &column);

	int **a2;
	a2 = (int **) malloc(row * sizeof(int *));
	for(i = 0; i < row; i++){
		a2[i] = (int *) malloc(column * sizeof(int));
	}

	//allocation of three dimentional int array

	int p, q, r;
	scanf("%d%d%d", &p, &q, &r);

	int ***a3;
	a3 = (int ***) malloc(p * sizeof(int **));
	for(i = 0; i < p; i++){
		a3[i] = (int **) malloc(q * sizeof(int *));
		for(j = 0; j < q; j++){
			a3[i][j] = (int *) malloc(r * sizeof(int));
		}
	}

	//allocaton of array of strings

	int n_;
	scanf("%d", &n);

	char **s = (char **) malloc(row * sizeof(char *));
	char t[123];
	for(i = 0; i < n; i++){
		scanf("%s", t);
		s[i] = strdup(t);
	}

	for(i = 0; i < n; i++){
		printf("%s\n", s[i]);
	}

	
	
	
}