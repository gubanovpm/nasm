#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE *inp = fopen("antideb", "rb");

	fseek(inp, 0, SEEK_END);
	int size = ftell(inp);
	fseek(inp, 0, SEEK_SET);
	
	unsigned char *text = (unsigned char *)malloc(sizeof(char) * size);
	fread(text, sizeof(char), size, inp);
	fclose(inp);

	for (int i = 0; i < size - 1; i++) {
		if ((*(text + i) == 0x75) && (*(text + i +1) == 0x14)) {
			*(text + i) = 0x74;
		}
	}

    FILE *out = fopen("antideb_patched", "wb");

	fwrite(text, sizeof(char), size, out);

	free(text);
    fclose(out);
    return 0;

}
