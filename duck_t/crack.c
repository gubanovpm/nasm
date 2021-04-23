#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE *input = fopen("source", "rb");
	FILE *output = fopen("cracked", "wb");
	
	fseek(input, sizeof(unsigned char), SEEK_END);
	long long int size = ftell(input);
	fclose(input);
	input = fopen("source", "rb");
	unsigned char *text = (unsigned char *)malloc(sizeof(unsigned char) * size);
	unsigned char *result = (unsigned char *)malloc(sizeof(unsigned char) * size);
	fread(text, sizeof(unsigned char), size, input);
	fclose(input);
	
	for (int i = 0; i < size; i++) {
		if ((i != size - 1) && (text[i] == 0x75) && (text[i + 1] == 0x11))
			result[i] = 0x74;
		else
			result[i] = text[i];
	}
	
	fwrite(result, sizeof(unsigned char), size - 1, output);
	fclose(output);
	free(text);
	free(result);
	return 0;

}
