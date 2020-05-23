#include <stdio.h>


int main () {
	
	int n, mask;
	scanf ("%d", &n);	

	for (mask = 31; mask >= 0; mask--) {
		if ( n & (1 << mask) ) {
			printf("1");
		}
		else {
			printf("0");
		}
	}

	return 0;
}