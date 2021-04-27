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
	unsigned char * text = (unsigned char *)malloc(sizeof(unsigned char) * sz);
	fread(text, sizeof(char), sz, inp);
	int it_count = (sz % 3 == 0) ? 0 : 1;
	it_count += sz/3;
	unsigned char *ans = (unsigned char *)malloc(sizeof(unsigned char) * it_count * 4);
	unsigned int mask = 63;
	for (long long int i = 0; i < it_count; i++) {
		int x1 = text[i * 3], x2 = text[i * 3 + 1], x3 = text[i * 3 + 2];
		if (i * 3 + 1 == sz) {
			x2 = 0;
			x3 = 0;
		}
		if (i * 3 + 2 == sz) {
			x3 = 0;
		}
		unsigned int x = ((unsigned int)(x1) << 16) + ((unsigned int)(x2) << 8) + (unsigned int)(x3);
		unsigned int a = ((x & (mask << 18)) >> 18), b = ((x & (mask << 12)) >> 12), c = ((x & (mask << 6)) >> 6), d = (x & mask);
		ans[i * 4] = char_set[a];
		ans[i * 4 + 1] = char_set[b];
		ans[i * 4 + 2] = char_set[c];
		ans[i * 4 + 3] = char_set[d];
	}
	if (sz % 3 == 2) {
		ans[it_count * 4 - 1] = char_set[64];
	}
	if (sz % 3 == 1) {
		ans[it_count * 4 - 1] = char_set[64];
		ans[it_count * 4 - 2] = char_set[64];
	}
	fwrite(ans, sizeof(char), it_count * 4, out);
	fclose(inp);
	fclose(out);
	free(text);
	free(ans);
	return 0;

}
