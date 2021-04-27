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
	x_f.fl = 0;
	x_db.db = 0;
	x_ld.ld = 0;
	for (int i = 8 * sizeof(long double) - 1; i >= 0; i--)
		x_ld.i128= x_ld.i128 & ((__int128)(0) << i);
	char s1[20];
	scanf("%s", s1);
	char fl = s1[0];
	if (s1[0] == 'l') {
		scanf("%s", s1);
		scanf("%Lg", &x_ld.ld);
	}
	else {
		if (fl == 'f')
			scanf("%f", &x_f.fl);
		else
			scanf("%lg", &x_db.db);
	}
	if (fl == 'f') {
		for (int i = 8 * sizeof(float) - 1; i >= 0 ; i--) {
			if ((x_f.u & ((unsigned)(1) << i)) == 0)
				printf("0");
			else
				printf("1");
			if ((8 * sizeof(float) - i) % 4 == 0)
				printf(" ");
		}
		printf("\n");
	}
	else if (fl == 'd') {
		for (int i = 8 * sizeof(double) - 1; i >= 0 ; i--) {
			if ((x_db.llu & ((unsigned long long)(1) << i)) == 0)
				printf("0");
			else
				printf("1");
			if ((8 * sizeof(double) - i) % 4 == 0)
				printf(" ");
		}
		printf("\n");
	}
	else {
		for (int i = 8 * sizeof(long double) - 1; i >= 0; i--) {
			if ((x_ld.i128 & ((__int128)(1) << i)) != 0)
				printf("1");
			else
				printf("0");
			if ((8 * sizeof(long double) - i) % 4 == 0)
				printf(" ");
		}
		printf("\n");
	}
	return 0;

}