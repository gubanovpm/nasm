#include <stdio.h>
#include <stdlib.h>

long double arr[20000001];

int cmp(const void *p1,const void *p2) {
	const long double a1 = *((const long double*)p1);
	const long double a2 = *((const long double*)p2);
	return (a1 > a2) ? 1 : 0 ;
}

int main() {

	long long int q = 0;
	long double d_s = 0;
	for (long long int i = 0; i < 20000001; i++) {
		if (scanf("%Lg", &arr[i]) == EOF)
			break;
		q++;
	}
	qsort(arr, q, sizeof(long double), cmp);
	for (long long int i = 0; i < q; i++) {
		d_s += arr[i];
	}
	printf("%0.20Lg\n", d_s);
	return 0;

}