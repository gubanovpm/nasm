#include <stdio.h>
#include <stdlib.h>

long long int ab(long long int x);

unsigned long long int ss_t[100001];
unsigned long long int ss_res[100001];

int main() {

	for (int i = 0; i < 100001; i++)
		ss_res[i] = 0;
	int n = 0, fl = 1, x_res = 0, first = 1;
	scanf("%d", &n);
	char s[50];
	int mn_ss = 0;
	for (int i = 0; i < n; i++) {
		int x = 0;
		int fl1 = 1;
		char num1[11], num2[11], num3[11];
		for (int j = 0; j < 11; j++) {
			num1[j] = 0;
			num2[j] = 0;
			num3[j] = 0;
		}
		int p = 0, op = 0, l1 = 0, l2 = 0, l3 = 0;
		int t = 0;
		scanf("%s", s);
		for (int j = 0; s[j] != '\0'; j++)
			s[j] = (s[j] >= 'a' && s[j] <= 'z') ? s[j] - 'a' + 'A' : s[j];
		while (s[p] != '+' && s[p] != '*') {
			t = (s[p] >= '0' && s[p] <= '9') ? s[p] - '0' : s[p] - 'A' + 10 ;
			num1[p] = t ;
			if (t > mn_ss)
				mn_ss = t;
			p++;
		}
		l1 = p;
		if (s[p] == '+')
			op = 1;
		p++;
		while (s[p] != '=') {
			t = (s[p] <= '9') ? s[p] - '0' : s[p] - 'A' + 10 ;
			num2[p - l1 - 1] = (s[p] <= '9') ? s[p] - '0' : s[p] - 'A' + 10;
			p++;
			if (t > mn_ss)
				mn_ss = t;
		}
		l2 = p - l1 - 1;
		p++;
		while (s[p] != '\0') {
			t = (s[p] <= '9') ? s[p] - '0' : s[p] - 'A' + 10 ;
			num3[p - l1 - l2 - 2] = t ;
			p++;
			if (t > mn_ss)
				mn_ss = t;
		}
		l3 = p - l1 - l2 - 2;
		if (op == 1) {
			int res[11];
			for (int j = 0; j < 11; j++)
				res[j] = 0;
			for (int j = 0; j < l3; j++) {
				res[j] = num3[l3 - j - 1];
				if (l1 - j - 1 >= 0)
					res[j] -= num1[l1 - j - 1];
				if (l2 - j - 1 >= 0)
					res[j] -= num2[l2 - j - 1];
			}
			int fnz = 0, lnz = 0;
			for (int j = 0; j < l3; j++)
				if (res[j] != 0) {
					fnz = j;
					break;
				}
			for (int j = 0; j < l3; j++)
				if (res[j] != 0)
					lnz = j;
			if (fnz == lnz && res[fnz] == 0)
				fl *= 1;
			if (res[fnz] != 0) {
				fl1 = 0;
				fl = 0;
			}
			if (res[fnz] != 0) {
				for (unsigned long long int j = mn_ss + 1; j <= (unsigned long long int)ab(res[fnz]); j++) {
					if (ab(res[fnz]) % j == 0) {
						unsigned long long int h[11], k = 1;
						for (int g = 0; g < 11; g++) {
							h[g] = k;
							k *= j;
						}
						unsigned long long int a1 = 0, a2 = 0, a3 = 0;
						for (int g = 0; g < l1; g++)
							a1 += num1[l1 - g - 1] * h[g];
						for (int g = 0; g < l2; g++)
							a2 += num2[l2 - g - 1] * h[g];
						for (int g = 0; g < l3; g++)
							a3 += num3[l3 - g - 1] * h[g];
						if (a1 + a2 == a3) {
							ss_t[x] = j;
							x++;
							fl = 0;
						}
					}
				}
			}
		}
		else {
			int res[20];
			for (int j = 0; j < 20; j++)
				res[j] = 0;
			if (l1 < l2) {
				for (int j = 0; j < l2; j++) {
					int t = num1[j];
					num1[j] = num2[j];
					num2[j] = t;
				}
				int t = l1;
				l1 = l2;
				l2 = t;
			}
			for (int j = 0; j < l1; j++) {
				for (int g = 0; g < l2; g++) {
					res[l1 + l2 - j - g - 2] += num1[j] * num2[g];
				}
			}
			for (int j = 0; j < l3; j++) {
				res[j] -= num3[l3 - j - 1];
			}
			int fnz = 0, lnz = 0;
			for (int j = 0; j < 20; j++)
				if (res[j] != 0) {
					fnz = j;
					break;
				}
			for (int j = 0; j < 20; j++)
				if (res[j] != 0)
					lnz = j;
			if (fnz == lnz && res[fnz] == 0)
				fl *= 1;
			if (res[fnz] != 0) {
				fl1 = 0;
				fl = 0;
			}
			if (res[fnz] != 0) {
				for (unsigned long long int j = mn_ss + 1; j <= (unsigned long long int)(ab(res[fnz])) ; j++) {
					if (ab(res[fnz]) % j == 0) {
						unsigned long long int h[11], k = 1;
						for (int g = 0; g < 11; g++) {
							h[g] = k;
							k *= j;
						}
						unsigned long long int a1 = 0, a2 = 0, a3 = 0;
						for (int g = 0; g < l1; g++)
							a1 += num1[l1 - g - 1] * h[g];
						for (int g = 0; g < l2; g++)
							a2 += num2[l2 - g - 1] * h[g];
						for (int g = 0; g < l3; g++)
							a3 += num3[l3 - g - 1] * h[g];
						//printf("%lld + %lld ? %lld\n", a1, a2, a3);
						if (a1 * a2 == a3) {
							ss_t[x] = j;
							x++;
							fl = 0;
						}
					}
				}
			}
		}
		for (int j = 0; j < x_res; j++) {
			int f = 0;
			for (int g = 0; g < x; g++)
				if (ss_res[j] == ss_t[g]) {
					f = 1;
					break;
				}
			if (!f && !fl1) {
				ss_res[j] = 0;
			}
		}
		if (first && !fl) {
			first = 0;
			x_res = x;
			for (int j = 0; j < x; j++)
				ss_res[j] = ss_t[j];
		}
	}
	int q = 0;
	unsigned long long int otv = 0;
	for (int i = 0; i < x_res; i++)
		if (ss_res[i] != 0 &&  ss_res[i] > (unsigned long long int)mn_ss) {
			q++;
			otv = ss_res[i];
		}
	if ((fl || q > 1) && n != 0)
		printf("-1\n");
	else if (q == 0)
		printf("0\n");
	else
		printf("%lld\n", otv);
	return 0;

}

long long int ab(long long int x) {
	return (x < 0) ? -x : x;
}
