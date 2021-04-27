#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	unsigned char inp = argv[argc - 1][1];
	unsigned char x = inp & 1;
	if (x)
		printf("ma\n");
	else
		printf("fe\n");
	return 0;

}