#include <stdio.h>


int main () {

	long long n;
	scanf ("%lld", &n);

	puts (n & (n - 1) ? "not a power of two" : "it's a power of two" );
	return 0;
}