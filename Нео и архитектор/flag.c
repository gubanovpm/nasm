#include <stdio.h>
#include <stdlib.h>

int main () {

	unsigned int cmnd = 0, fl = 0, mask = 1 << 7;
	unsigned char reg[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (1) {
		scanf("%u", &cmnd);
		unsigned char f = cmnd & mask;
		if (f != 0 && !fl)
			cmnd = cmnd & (255 - 128);
		else if (f != 0) {
			cmnd = cmnd & (255 - 128);
			unsigned char a = 0, b = 0;
			if (cmnd != 0 && cmnd != 4)
				scanf("%hhu%hhu", &a, &b);
			continue;
		}
		if (cmnd == 0)
			break;
		if (cmnd == 4) {
			for (int i = 5; i < 9; i++)
				printf("%u ", reg[i]);
			printf("\n");
		}
		unsigned char a = 0, b = 0;
		if (cmnd == 1) {
			scanf("%hhu%hhu", &a, &b);
			reg[a] += reg[b];
			if (reg[a] == 0)
				fl = 0;
			else
				fl = 1;
		}
		if (cmnd == 2) {
			scanf("%hhu%hhu", &a, &b);
			reg[a] -= reg[b];
			if (reg[a] == 0)
				fl = 0;
			else
				fl = 1;
		}
		if (cmnd == 3) {
			scanf("%hhu%hhu", &a, &b);
			reg[a] = b;
			if (reg[a] == 0)
				fl = 0;
			else
				fl = 1;
		}
	}
	return 0;

}