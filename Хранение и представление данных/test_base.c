#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE *inp = fopen("data", "rb");
	FILE *out = fopen("base64", "wb");
	if (inp == NULL)
		return 0;
	if (out == NULL)
		return 0;
	fseek(inp, 0, SEEK_END);
	long long int sz = ftell(inp);
	fseek(inp, 0, SEEK_SET);
	char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	char *text = (char *)malloc(sizeof(char) * sz);
	char *ans = (char *)malloc(sizeof(char) * sz / 3 * 4);
	fread(text, sizeof(char), sz, inp);
	unsigned int mask = 63;
	for (int i = 0; i < sz / 3; i++) {
		unsigned int x = ((unsigned int)(text[i * 3]) << 16) + ((unsigned int)(text[i * 3 + 1]) << 8) + (unsigned int)(text[i * 3 + 2]);
		unsigned int a = ((x & (mask << 18)) >> 18), b = ((x & (mask << 12)) >> 12), c = ((x & (mask << 6)) >> 6), d = (x & mask);
		ans[i * 4] = char_set[a];
		ans[i * 4 + 1] = char_set[b];
		ans[i * 4 + 2] = char_set[c];
		ans[i * 4 + 3] = char_set[d];
	}
	fwrite(ans, sizeof(char), sz / 3 * 4, out);
	fclose(inp);
	fclose(out);
	return 0;

}