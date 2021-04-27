#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *earg[]) {

	unsigned char x = 0;
	for (int i = 0 ;  ; i++) {
		if (earg[i][0] == 'C'&& earg[i][1] == 'O' && earg[i][2] == 'D' && earg[i][3] == 'E') {
			x = (earg[i][6] >= 'a' && earg[i][6] <= 'f') ? earg[i][6] - 'a' + 'A' : earg[i][6] ;
			x = (earg[i][6] >= 'A' && earg[i][6] <= 'F') ? earg[i][6] - 'A' + 10 : earg[i][6] - '0' ;
			break;
		}
	}
	if (((x >> 2) & (unsigned char)(1)) != 0)
		printf("ha\n");
	else
		printf("nh\n");
	char *s = argv[argc - 1];
	s[0] = s[1];
	return 0;

}
