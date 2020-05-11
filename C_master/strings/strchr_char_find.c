#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find(char *s, char a){
	return strchr(s, a) != NULL;
}

int find(char *s, char a, char b){
	return (s = strchr(s, a)) != NULL && strchr(s + 1, b) != NULL;
}

int main(){

	char s[] = "samioisass", a = 'o';
	puts( find(s, a) ? "a exists in s" : "a doesn't exist in s" );

	a = 'f';
	puts( find(s, a) ? "a exists in s" : "a doesn't exist in s" );

	// lets check if b exist after a
	a = 'm';
	char b = 'i';
	puts(find(s, a, b) ? "b exists after a" : "b doesn't exist after a");

	//related problem : https://codeforces.com/contest/5/problem/A


}