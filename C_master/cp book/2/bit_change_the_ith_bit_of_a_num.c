#include <stdio.h>

void print_bit (int n) {
	int mask;

	for (mask = 31; mask >= 0; mask--) {
		if ( n & (1 << mask) ) printf("1");
		else printf("0");
	}
	printf("\n");
}

int change_bit (int n, int k, int x) {
	if (x) {
		return ( n | (1 << k) );
	}
	else {
		return ( n & ~(1 << k) );
	}
}

int main () {
	
	int n, k, x, newnum;
	scanf ("%d", &n);

	printf ("bit representation of %d is :\n", n);
	print_bit (n);

	printf ("out of 32 what number of bits you want to change ?\n");
	scanf ("%d", &k);
	k =  32 - k;

	printf ("do you want to change it to 0 or 1 ?\n");
	scanf ("%d", &x);

	newnum = change_bit (n, k, x);
	
	printf("current bit representation of %d is :\n", newnum);
	print_bit (newnum);

	return 0;
}