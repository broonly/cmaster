#include <stdio.h>
#include <string.h>

void reverse(char *s){
	char r, *t;

	for(t = s + strlen(s) - 1; s < t ; s++, t--){
		r = *s, *s = *t, *t = r;
	}
}

int main(){

	char s[10001];
	scanf("%s", s);
	
	reverse(s);
	
	printf("%s\n", s);
}