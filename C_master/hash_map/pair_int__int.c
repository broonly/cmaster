#include <stdio.h>
#include <stdlib.h>

#define	HASHSIZE	101

struct info{
	struct info *next;
	int a[2];
	int cnt;
} *hashtab[HASHSIZE];

int hash(int x, int y){
	int a[2] = {x, y};
	int hashval, i;
	
	//please make sure x + y + 1000249 add upto zero or increase that number

	for(hashval = 0, i = 0; i < 2; i++){
		hashval = (a[i] + 1000249 + 31 * hashval) % HASHSIZE;
	}
	return hashval;
}

struct info *lookup(int x, int y){
	struct info *p;
	int h = hash(x, y);

	for(p = hashtab[h]; p != NULL; p = p->next){
		if(x == p->a[0] && y == p->a[1]){
			return p;
		}
	}
	return NULL;
}

void update(int x, int y){
	struct info *p;
	int h = hash(x, y);
	
	if((p = lookup(x, y)) == NULL){
		p = (struct info *) malloc(sizeof(*p));
		p->a[0] = x;
		p->a[1] = y;
		p->cnt = 0;
		p->next = hashtab[h];
		hashtab[h] = p;
	}
	p->cnt += 1;
}

int main(){

	int x, y, i;
	struct info *p;

	for(i = 0; i < 10; i++){
		scanf("%d%d", &x, &y);
		update(x, y);
	}

	for(i = 0; i < HASHSIZE; i++){
		for(p = hashtab[i]; p != NULL; p = p->next){
			printf("%d %d %d\n", p->a[0], p->a[1], p->cnt);
		}
	}
}