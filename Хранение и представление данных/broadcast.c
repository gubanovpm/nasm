#include <stdio.h>
#include <stdlib.h>

int main() {

	unsigned int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	unsigned int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
	unsigned char c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	scanf("%u.%u.%u.%u", &a1, &a2, &a3, &a4);
	scanf("%u.%u.%u.%u", &b1, &b2, &b3, &b4);
	unsigned long long int a = 0, b = 0;
	a = (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
	b = (b1 << 24) + (b2 << 16) + (b3 << 8) + b4;
	//printf("%llu %llu\n", a, b);
	unsigned long long int res = 0;
	res = ((b & a) | (~(unsigned int)b)) ;
	c1 = res % 256;
	res /= 256;
	c2 = res % 256;
	res /= 256;
	c3 = res % 256;
	res /= 256;
	c4 = res;
	printf("%u.%u.%u.%u\n", c4, c3, c2, c1);
	return 0;

} 