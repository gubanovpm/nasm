#include <stdio.h>
#include <stdlib.h>

char arr[25000001];

int main() {

	long long x = 0;
	scanf("%lld", &x);
	long long int k = x - 1;
	for (long long int i = 2; i <= x; i++) {
		if ((arr[i/8] & (1 << i%8)) == 0) {
			for (long long int j = 2 * i; j <= x ; j += i) {
				arr[j/8] = arr[j/8] | (1 << j%8);
			}
		}
		else {
			k--;
		}
	}
	printf("%lld\n", k);
	return 0;

}