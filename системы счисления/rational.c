#include <stdio.h>
#include <stdlib.h>

int len(char *s);
void rev_str(char *s);
double power(double osn, int p);

int main(){
	
	char s[31], int_part[31], fl_part[31];
	for (int i = 0; i < 31; i++){
		s[i] = '\0';
		int_part[i] = '\0';
		fl_part[i] = '\0';
	}
	scanf("%s", s);
	int k = 0, q = 0;
	while (s[k] != '.' && s[k] != '\0') {
		int_part[k] = s[k];
		k++;
	}
	if (s[k] == '.') {
		k++;
		while (s[k] != '\0') {
			fl_part[q] = s[k];
			q++;
			k++;
		}
	}
	rev_str(int_part);
	double ip = 0, fp = 0;
	for (int i = 0; i < len(int_part); i++)
		ip += (int_part[i] - '0') * power(2, i);
	for (int i = 0; i < len(fl_part); i++)
		fp += (fl_part[i] - '0') * power(0.5, i + 1);
	printf("%.12lf\n", ip + fp);
	return 0;
	
}

int len(char *s) {
	int l = 0;
	while(s[l++]!='\0')
		;
	return l-1;
}

void rev_str(char *s) {
	int l = len(s);
	char t = 0;
	for (int i = 0; i < l/2; i++) {
		t = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = t;
	}
}

double power(double osn, int p) {
	double res = 1;
	for (int i = 0; i < p; i++) {
		res *= osn;
	}
	return res;
}
