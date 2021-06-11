#include <stdio.h>
#include <stdlib.h>

int len(char *s);

int main() {
	
	char num1[1001], rev1[1001];
	char num2[1001], rev2[1001];
	for (int i = 0; i < 1001; i++) {
		num1[i] = '0';
		num2[i] = '0';
		rev1[i] = '0';
		rev2[i] = '0';
	}
	scanf("%s", num1);
	scanf("%s", num2);
	int l1 = len(num1), l2 = len(num2);
	for (int i = l1 - 1 ; i > 0 ; i--)
		rev1[l1 - i - 1] = num1[i - 1];
	for (int i = l2 - 1 ; i > 0 ; i--)
		rev2[l2 - i - 1] = num2[i - 1];
//	rev1[l1] = '0';
//	rev2[l2] = '0';
	int l = (l1 > l2) ? l1 : l2;
	l--;
	char res[1002];
	char x[2]; x[0] = '0'; x[1] = '0';
//	printf("%d\n", l1);
	for (int i = 0; i <= l ; i++){
		int sm = x[1] + rev1[i] + rev2[i];
//		printf("%c + %c + %c =", x[1], rev1[i], rev2[i]);
		if (sm == '0' + '1' + '1') {
			x[0] = '$';
			x[1] = '1';
		}
		if (sm == '0' + '$' + '$') {
			x[0] = '1';
			x[1] = '$';
		}
		if (sm == '0' + '$' + '1' || sm == '0' + '0' + '0') {
			x[0] = '0';
			x[1] = '0';
		}
		if (sm == '$' + '1' + '1') {
			x[0] = '1';
			x[1] = '0';
		}
		if (sm == '$' + '$' + '1') {
			x[0] = '$';
			x[1] = '0';
		}
		if (sm == '1' + '1' + '1' || sm == '$' + '$' + '$') {
			x[0] = '0';
			x[1] = sm / 3;
		}
		if (sm == '1' + '0' + '0' || sm == '$' + '0' + '0') {
			x[0] = sm - '0' - '0';
			x[1] = '0';
		}
//		printf("%c%c\n", x[1], x[0]);
		res[i] = x[0];
	}
	int fl = 0;
	for (int i = l; i >= 0; i--) {
		if (fl == 0 && res[i] =='0')
			continue;
		if ((fl == 0 && res[i] != '0') || fl == 1) {
			printf("%c", res[i]);
			fl = 1;
		}
	}
	if (fl == 0)
		printf("0");
	printf("\n");
	return 0;
	
}

int len(char *s) {
	int l = 0;
	while(s[l++] != '\0')
		;
	return l;
}
