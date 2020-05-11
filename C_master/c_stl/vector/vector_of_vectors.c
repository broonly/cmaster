#include <stdio.h>
#include <stdlib.h>

#define N 	1000

struct info{
	int *v;
	int c;
} v[N + 1];

void rlc(struct info *vector, int u, int c){
	vector[u].v = (int *) realloc(vector[u].v, c * sizeof *vector[u].v);
}

void push(struct info *vector, int u, int v){
	int c;
	c = vector[u].c += 1;

	rlc(vector, u, c);
	
	vector[u].v[c - 1] = v; 
}

int main(){
	int n, k, a, b, i, j;
	scanf("%d%d", &n, &k);
	
	while(k--){
		scanf("%d%d", &a, &b);
		push(v, a, b);
	}

	for(i = 0; i <= n; i++){
		for(j = 0; j < v[i].c; j++){
			printf("%d ", v[i].v[j]);
		}
		puts("");
	}

}