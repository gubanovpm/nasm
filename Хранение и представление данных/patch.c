#include <stdio.h>
#include <stdlib.h>

unsigned int patch(unsigned int data) {
	unsigned int mask = 1;
	for (int i = 0; i < 16; i++)
		mask = ((mask << 1) | 1);
	return (mask & data);
}

int main() {

	printf("%u\n", patch(231072));
	return 0;

}