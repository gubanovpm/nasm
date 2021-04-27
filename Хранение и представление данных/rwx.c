#include <stdio.h>
#include <stdlib.h>

void translate(int x);

int main(){

	char num[4];
	int a = 0, b = 0, c = 0; 
	scanf("%s", num);
	a = num[0] - '0';
	b = num[1] - '0';
	c = num[2] - '0';
	char arr[8][4] = {"---\0", "--x\0", "-w-\0", "-wx\0", "r--\0", "r-x\0", "rw-\0", "rwx\0"};
	printf("%s%s%s\n", arr[a], arr[b], arr[c]);
	return 0;

}
