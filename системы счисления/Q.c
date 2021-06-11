#include <stdio.h>
#include <stdlib.h>

unsigned long long int power(int osn, int p) {
	unsigned long long int t = 1;
	for (int i = 0; i < p; i++)
		t *= osn;
	return t;
}

int main() {
	
	int osn = 0;
	unsigned long long int x = 0, z = 0;
	int x1 = 0, x2 = 0, x3 = 0;
	int fl = 0;
	scanf("%d", &osn);
	for (int d1 = osn - 1 ; d1 >= 0 ; d1--) {
		if (fl == 1)
			break;
		for (int d2 = osn - 1 ; d2 >= 0 ; d2--) {
			if (fl == 1)
				break;
			for (int d3 = osn - 1 ; d3 >= 0 ; d3--) {
				x = d1 * osn * osn + d2 * osn + d3;
				z = x;
				x *= x;
				unsigned long long int t = 1;
				int k = 0;
				while (t < x) {
					k++;
					t *= osn;
				}
				for (int i = 1; i <= k; i++) {
					if (i > k - 3) {
						if (i == k) {
							x1 = x % osn;
						}
						if (i == k - 1) {
							x2 = x / osn;
						}
						if (i == k - 2) {
							x3 = x / (osn * osn);
						}
					}
					unsigned long long int p = power(osn, k - i);
					x = x % p;
				}
				if (x1 == d3 && x2 == d2 && x3 == d1) {
					printf("%lld\n", z);
					fl = 1;
					break;
				}
			}
		}
	}
	return 0;
	
}
