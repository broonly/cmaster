#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 2001
#define N 	200000

struct vector {
	int *a;
	int c;
} v[N + 1];

struct map {
	struct map *next;
	int val;
	int i, j;
} *m[HASHSIZE];

void rlc (struct vector *v, int i, int c) {
	v[i].a = (int *) realloc(v[i].a, c * sizeof *v[i].a);
}

void push (struct vector *v, int i, int a) {
	int c;
	c = v[i].c += 1;
	rlc(v, i, c);
	v[i].a[c - 1] = a;
}

int hash (int s) {
	int h;
	h = ( 99312255569 + s * 31) % HASHSIZE;
	return h; 
}

struct map *lookup(int s, int i) {
	int h;
	struct map *p;
	h = hash(s);

	for (p = m[h]; p != NULL; p = p->next) {
		if(p->val == s && p->i == i) {
			return p;
		}
	}
	return NULL;
}

void update (int s, int i, int j) {
	struct map *p;
	int h = hash(s);

	if ((p = lookup(s, i)) == NULL) {
		p = (struct map *) malloc(sizeof *p);

		p->val = s;
		p->i = i;
		p->j = j;

		p->next = m[h];
		m[h] = p;
	}
}

struct map *find (int s, int i) {
	struct map *p;
	int h = hash(s);

	for (p = m[h]; p != NULL; p = p->next) {
		if(p->val == s && p->i != i) {
			return p;
		}
	}
	return NULL;
}

int main() {
	int k, n, a, i, j, f, s, t, s1, s1_, s2, s2_;
	struct map *p;
	scanf("%d", &k);

	f = 0;
	for (i = 0; i < k; i++) {
		scanf("%d", &n);

		s = 0;
		for (j = 0; j < n; j++) {
			scanf("%d", &a);
			push(v, i, a);
			s += a;
		}

		if (f) continue;

		for (j = 0; j < n; j++) {
			t = s - v[i].a[j];
			update(t, i + 1, j + 1);
			p = find(t, i + 1);

			if (p != NULL) {
				f = 1;
				s1 = p->i;
				s1_ = p->j;
				s2 = i + 1;
				s2_ = j + 1;
				break;
			}
		}
	}


	if (f) {
		printf("YES\n%d %d\n%d %d\n", s1, s1_, s2, s2_);
	} 
	else {
		printf("NO\n");
	}


	return 0;
}