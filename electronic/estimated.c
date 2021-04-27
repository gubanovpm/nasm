#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE *inp = fopen("source", "rb");

	fseek(inp, 0, SEEK_END);
	int size = ftell(inp);
	fseek(inp, 0, SEEK_SET);
	
	unsigned char *text = (unsigned char *)malloc(sizeof(char) * size);
	fread(text, sizeof(char), size, inp);
	fclose(inp);

	for (int i = 0; i < size - 3; i++) {
		if (*((int *)((void *)(text + i))) == 0x3B9ACA00)
			*((int *)((void *)(text + i))) = 0x779ACA00;
	}

    FILE *out = fopen("cracked", "wb");

	fwrite(text, sizeof(char), size, out);

	free(text);
    fclose(out);
    return 0;

}
