#include <stdio.h>
#include <stdlib.h>

int main() {

	union fl_int {
		float fl;
		unsigned int u;
	} x_f;
	union db_int {
		double db;
		unsigned long long int llu;
	} x_db;
	union ld {
		long double ld;
		__int128 i128;
	} x_ld;
	x_f.fl = 1;
	x_db.db = 1;
	x_ld.ld = 1;
	int k = 0;
	char c = getchar(), fl = 0;
	fl = c;
	if (c == 'l') {
		while ((c = getchar()) != ' ')
			;
		while ((c = getchar()) != '\n')
			;
	}
	else
		while ((c = getchar()) != '\n')
			;
	if (fl == 'f') {
		while ((x_f.u & (1 << k)) == 0)
			k++;
		printf("%d\n", k);
	}
	else if (fl == 'd') {
		for (unsigned int i = 0; i < 8 * sizeof(double) ; i++)
			if ((x_db.llu & ((unsigned long long)(1) << i)) != 0) {
				printf("%d\n", i);
				break;
			}
	}
	else {
		for (unsigned int i = 0; i < 8 * sizeof(long double) ; i++)
			if ((x_ld.i128 & ((__int128)(1) << i)) != 0) {
				printf("%d\n", i);
				break;
			}
	}
	return 0;

}