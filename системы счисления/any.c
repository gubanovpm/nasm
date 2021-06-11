#include <stdio.h>
#include <stdlib.h>

char int2char(int a);
int char2int(char c);
int len(char *s);
char upcase(char c);
long long int power(int osn, int p);
void rev_str(char *s);

int main() {

	int ss1 = 0, ss2 = 0, p = 0;
	char num[33];
	char ans[33];
	for (int i = 0; i < 33; i++)
		ans[i] = '\0';
	long long int res = 0;
	scanf("%d", &ss1);
	scanf("%s", num);
	scanf("%d", &ss2);
	int l = len(num) - 1;
	for (int i = l; i > 0; i--) {
		int x = char2int(upcase(num[i-1]));
		res += x * power(ss1, l - i);
	}
//	printf("%lld\n", res);
	if (res == 0)
		ans[0] = '0';
	while (res > 0) {
		ans[p] = int2char(res % ss2);
		p++;
		res /= ss2;
	}
	rev_str(ans);
	printf("%s\n", ans);
	return 0;

}

char upcase(char c) {
	return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c ;
}

char int2char(int a) {
	return (a < 10) ? a + '0' : a - 10 + 'A';
}

int char2int(char c) {
	return (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
}

int len(char *s) {
	int l = 0;
	while(s[l++] != '\0')
		;
	return l;
}

long long int power(int osn, int p) {
	long long int res = 1;
	for (int i = 0; i < p; i++)
		res *= osn;
	return res;
}

void rev_str(char *s) {
	int l = len(s) - 1;
	char t = 0;
	for (int i = 0; i < l/2; i++) {
		t = s[i];
		s[i] = s[l-i-1];
		s[l-i-1] = t;
	}
}
