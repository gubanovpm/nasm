#include <stdio.h>
#include <stdlib.h>

int main() {

	unsigned int i_ebx = 0x756e6547;
	unsigned int i_edx = 0x49656e69;
	unsigned int i_ecx = 0x6c65746e;
	
	//unsigned int salt = 0xfe65f;
	
	unsigned int a_ebx = 0x68747541;
	unsigned int a_edx = 0x69746E65;
	unsigned int a_ecx = 0x444D4163;
	
	unsigned int x = 0;
	scanf("%d", &x);
	
	printf("%d\n", x ^ i_ebx ^ i_edx ^ i_ecx ^ a_ebx ^ a_edx ^ a_ecx);
	
	return 0;

}
