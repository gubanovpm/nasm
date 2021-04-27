#include <stdio.h>
#include <stdlib.h>

int main() {
	
	unsigned char a = 0, b = 0 ;
	scanf("%hhx%hhx", &a, &b);
	return a^b;
	
}
