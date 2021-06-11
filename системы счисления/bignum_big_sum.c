#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s1[1001];
	char s2[1001];
	char result[1002];
	for (int i = 0; i < 1002; i++)
		result[i] = '\0';
	scanf("%s", s1);
	scanf("%s", s2);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if (l2 > l1) {
		char temp[1001];
		for (int i = 0; i <= l1; i++)
			temp[i] = s1[i];
		for (int i = 0; i <= l2 ; i++)
			s1[i] = s2[i];
		for (int i = 0; i <= l1 ; i++)
			s2[i] = temp[i];
		int t = l1;
		l1 = l2;
		l2 = t;
	}
	int ost = 0;
	for (int i = 0; i < l2 ; i++) {
		int x = (int)(s2[l2 - i - 1] - '0') + (int)(s1[l1 - i - 1] - '0') + ost;
		ost = x / 2;
		x = x % 2;
		result[l1 - i] = x + '0';
	}
	for (int i = l2; i < l1; i++) {
		int x = ost + s1[l1 - i - 1] - '0';
		ost = x / 2;
		x = x % 2;
		result[l1 - i] = x + '0'; 
	}
	result[0] = ost + '0';
	unsigned int i = 0;
	while (result[i] == '0')
		i++;
	if (i == strlen(result))
		printf("0");
	else
		for (unsigned int j = i; j < strlen(result); j++)
			printf("%c", result[j]);
	printf("\n");
	return 0;
}
