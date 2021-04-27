#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef REGISTERS
#define REGISTERS 4
#endif 

int main() {

	unsigned char n_reg = REGISTERS;
	if (n_reg > 4 || n_reg <= 0) {
		printf("-1\n");
		return 0;
	}
	int cmnd = 0;
	unsigned char reg[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (1) {
		scanf("%d", &cmnd);
		if (cmnd == 0)
			break;
		if (cmnd == 4) {
			for (int i = 5; i < 5 + n_reg; i++)
				printf("%hhu ", reg[i]);
			printf("\n");
		}
		else {
			unsigned char x1 = 0, x2 = 0;
			scanf("%hhd%hhd", &x1, &x2);
			if (cmnd == 1) {
				if ((n_reg  + 5 > x1) && (n_reg + 5 > x2) && (x2 > 4) && (x1 > 4))
					reg[(int)x1] += reg[(int)x2];
				else {
					printf("-1\n");
					return 0;
				}
			}
			if (cmnd == 2) {
				if ((n_reg + 5 > x1) && (n_reg + 5 > x2) && x2 > 4 && x1 > 4)
					reg[(int)x1] -= reg[(int)x2];
				else {
					printf("-1\n");
					return 0;
				}
			}
			if (cmnd == 3) {
				if ((n_reg + 5) > x1 && x1 > 4)
					reg[(int)x1] = x2;
				else {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	return 0;
}