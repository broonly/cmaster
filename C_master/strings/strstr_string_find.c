#include <stdio.h>
#include <string.h>

int find(char *s, char *a){
	return strstr(s, a) != NULL;
}

int find(char *s, char *a, char *b){
	return (s = strstr(s, a)) != NULL && strstr(s + strlen(a), b) != NULL;
}

int main(){
	char s[] = "samioisass", a[] = "ass";
	puts(strstr(s , a) ? "a exists in s" : "a doesn't exist in s"); 

	//let's check if a & b exist and both don't overlap

	char b[] = "mio";

	int ok1 = find(s, a, b);
	int ok2 = find(s, b, a);
	
	puts(ok1 || ok2 ? "yes" : "no");

	// it can be used as substr check, play with it
	//related problem : 1. https://codeforces.com/contest/550/problem/A
	// 2. https://codeforces.com/contest/8/problem/A
}