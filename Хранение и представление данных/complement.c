#include <stdio.h>
#include <stdlib.h>

int main() {

	signed char x = 0;
	scanf("%hhd", &x);
	for (int i = 7; i >= 0; i--)
		if ((x & ((char)1 << i)) != 0)
			printf("1");
		else
			printf("0");
	printf("\n");
	return 0;

}