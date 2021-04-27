#include <stdio.h>
#include <stdlib.h>

char arr[12500001];

int main() {

	long long int v = 0, n = 0, inf = 0, x = 0, p = 0, k = 0, q = 0;
	scanf("%lld%lld", &v, &n);
	for (int i = 0; i < v ; i++) {
		k = 2;
		p = 1;
		q = 1;
		scanf("%lld", &x);
		int fl = (arr[x/8] & (1 << x%8));
		if (fl == 0) {
			inf++;
			arr[x/8] = (arr[x/8] | (1 << x%8));
		}
		long long int j = 2 * x;
		while  (j < n) {
			int f = (arr[j/8] & (1 << j%8));
			if (f == 0) {
				inf++;
				arr[j/8] = (arr[j/8] | (1 << j%8));
			}
			k++;
			j = x * k + q;
			p++;
			//printf("%lld\n", j);
			q += p;
		}
	}
	printf("%lld\n", inf);
	return 0;

}