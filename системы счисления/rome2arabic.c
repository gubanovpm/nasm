#include <stdio.h>
#include <stdlib.h>

char upcase(char c);
int len(char *s);

int main () {
	char rome_num[25];
	int res = 0, x = 0;
	int pred = 0, sm = 0;
	scanf("%s", rome_num); 
	int l = len(rome_num);
	
	for (int i = 0 ; i < l ; i++ ){
		pred = x;
		if (rome_num[i] == 'I')
			x = 1;
		if (rome_num[i] == 'V')
			x = 5;
		if (rome_num[i] == 'X')
			x = 10;
		if (rome_num[i] == 'L')
			x = 50;
		if (rome_num[i] == 'C')
			x = 100;
		if (rome_num[i] == 'D')
			x = 500;
		if (rome_num[i] == 'M')
			x = 1000;
		if (x > pred)
			sm = -2 * pred;
		else
			sm = 0;
		res += (sm + x);
	}
	printf("%d\n", res);
	return 0;
	
}

char upcase(char c) {
	return (c>= 'a' && c<='z') ? c - 'a' + 'A' : c ;
}

int len(char *s) {
	int l = 0;
	while (s[l++] != '\0')
		;
	return l-1;
}
