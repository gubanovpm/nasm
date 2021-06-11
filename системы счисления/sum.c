#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long unsigned int power(long long unsigned int a) {
	long long unsigned int x = 1;
	for (long long unsigned int i = 0; i < a; i++)
		x *= 27 ;
	return x;
}

int main(int argc, char *argv[]) {
	float x = argc;
	unsigned int y = 0;
	scanf("%f%x", &x, &y);
	int l = strlen(argv[1]);
	long long unsigned int z = 0;
	for (int i = 0; i < l; i++) {
		char ch_num = argv[1][l - i - 1];
		int num = 0;
		if (ch_num >= '0' && ch_num <= '9')
			num = (int)(ch_num - '0');
		else
			num = (int)(ch_num - 'A');
		z += num * power(i);
	}
	printf("%.3f\n", x + y + z);
	return 0;
}
