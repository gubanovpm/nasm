#include <stdio.h>
#include <stdlib.h>

int main() {

	unsigned char x = 0;
	FILE *inp = fopen("bit_3.dat", "r");
	if (inp == NULL)
		return 0;
	fscanf(inp, "%hhx", &x);
	fclose(inp);
	FILE *out = fopen("bit_3.ans", "w");
	if (out == NULL)
		return 0;
	unsigned char ans = (x >> 4) & 3;
	char result[4][3] = {"bn\0", "rd\0" , "bw\0" , "bk\0"};
	fprintf(out, "%s\n", result[ans]);
	fclose(out);
	return 0;

}