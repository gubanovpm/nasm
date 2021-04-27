#include <stdio.h>
#include <stdlib.h>

int main() {

	unsigned char x = 0;
	scanf("%hhx", &x);
	if ((x & (unsigned char)(1)) != 0)
		printf("ma ");
	else 
		printf("fe ");
	x = x >> 1;
	if ((x & (unsigned char)(1)) != 0)
		printf("cl ");
	else 
		printf("du ");
	x = x >> 1;
	if ((x & (unsigned char)(1)) != 0)
		printf("ha ");
	else 
		printf("nh ");
	x = x >> 1;
	if ((x & (unsigned char)(1)) != 0)
		printf("tr ");
	else 
		printf("sk ");
	x = x >> 1;
	unsigned char ans = 0;
	char res1[4][3] = {"bn\0", "rd\0", "bw\0", "bk\0"} ;
	char res2[4][3] = {"bu\0", "ge\0", "gy\0", "da\0"} ;
	ans = x & 3;
	x = x >> 2;
	printf("%s ", res1[ans]);
	ans = x & 3;
	printf("%s\n", res2[ans]);
	return 0;
	
}