#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE	101

struct info{
	struct info *next;
	char *s;
	int cnt;
} *hastab[HASHSIZE];

int hash(char *s){
	int hashval , i;
	for(hashval = 0; *s != '\0'; s++){
		hashval = (*s + 31 * hashval) % HASHSIZE;
	}
	return hashval;
}

struct info *lookup(char *s){
	struct info *p;
	int h = hash(s);
	
	for(p = hastab[h]; p != NULL; p = p->next){
		if(strcmp(s, p->s) == 0){
			return p;
		}
	}
	return NULL;
}

void update(char *s){
	struct info *p;
	int h = hash(s);
	
	if((p = lookup(s)) == NULL){
		p = (struct info *) malloc(sizeof(*p));
		
		p->s = strdup(s);
		p->cnt = 0;
		p->next = hastab[h];
		hastab[h] = p;
	}
	p->cnt += 1;
}


int main(){

	int  i;
	char s[1000];
	struct info *p;

	for(i = 0; i < 10; i++){
		scanf("%s", s);
		update(s);
	}

	for(i = 0; i < HASHSIZE; i++){
		for(p = hastab[i]; p != NULL; p = p->next){
			printf("%s %d\n", p->s, p->cnt);
		}
	}



	return 0;
}