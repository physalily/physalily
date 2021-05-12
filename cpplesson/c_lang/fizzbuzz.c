#include <stdio.h>

int main(void) {
	int i, result;
	for (i = 0; i < 100; i++ ) {
		printf("No. %3d:", i);
		if ( 0 == i % 3 ) printf("FIZZ ");
		if ( 0 == i % 5 ) printf("BUZZ");
		printf("\n");
	}
	return 0;
}
