#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int mn(int a, int b);

int main() {

	FILE *inp = fopen("cuda.in", "r");
	FILE *out = fopen("cuda.out", "w");
	
	if (inp == NULL || out == NULL)
		return 0;
	
	unsigned int str_on_block = 0, reg_on_str = 0, diff_mem = 0;
	fscanf(inp, "%d %d %d", &str_on_block, &reg_on_str, &diff_mem);
	fclose(inp);
	
	unsigned int usedstr = (32 - (str_on_block % 32)) % 32 + str_on_block ;
	//printf("%u\n", usedstr);
	unsigned int real_reg = reg_on_str % 2 + reg_on_str;
	//printf("%u\n", real_reg);
	unsigned int used_reg = usedstr * real_reg;
	//printf("%u\n", used_reg);
	unsigned int gran_mem = (128 - (diff_mem % 128)) % 128 + diff_mem;
	//printf("%u\n", gran_mem);
	int block1 = 1536 / usedstr ;
	int block2 = 32768 / used_reg ;
	if (gran_mem == 0)
		gran_mem = 1;
	int block3 = 49152 / gran_mem ;
	int block = mn(mn(block1, block2), block3) ;
	int ans = round((double)(block * str_on_block * 100 ) / 1536);
	//printf("%d %d %d\n", block1 , block2 , block3);
	
	fprintf(out,"%d\n", ans);
	fclose(out);
	return 0;

}

int mn(int a, int b) {
	return (a < b) ? a : b ;
}