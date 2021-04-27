#include <stdio.h>
#include <stdlib.h>

int main () {

	char s[257];
	unsigned char x = 0, fl = 255;
	const unsigned char c1 = 1, c2 = 255;
	int p = 0;
	for (int i = 0; i < 152; i++)
		s[i] = '\0';
	fgets (s, 256, stdin);
	//printf("%s\n", s);
	while (s[p] != '\0') {
		// gen
		if ((s[p] == 'm' && s[p + 1] == 'a') && ((fl & c1) != 0)) {
			fl = fl & (c2 << 1);
			x = x | 1;
		}
		if ((s[p] == 'f' && s[p + 1] == 'e') && ((fl & c1) != 0))
			fl = fl & (c2 << 1);
		// intel
		if ((s[p] == 'c' && s[p + 1] == 'l') && ((fl & (c1 << 1)) != 0)) {
			fl = fl & ((c2 << 2) | c1);
			x = x | (c1 << 1);
		}
		if ((s[p] == 'd' && s[p + 1] == 'u') && ((fl & (c1 << 1)) != 0)) 
			fl = fl & ((c2 << 2) | c1);
		// hat
		if ((s[p] == 'h' && s[p + 1] == 'a') && ((fl & (c1 << 2)) != 0)) {
			fl = fl & ((c2 << 3) | (unsigned char)(3));
			x = x | (c1 << 2);
		}
		if ((s[p] == 'n' && s[p + 1] == 'h') && ((fl & (c1 << 2)) != 0)) 
			fl = fl & ((c2 << 3) | (unsigned char)(3));
		// tr - sk
		if ((s[p] == 't' && s[p + 1] == 'r') && ((fl & (c1 << 3)) != 0)) {
			fl = fl & (c2 << 4 | (unsigned char)(7));
			x = x | (c1 << 3);
		}
		if ((s[p] == 's' && s[p + 1] == 'k') && ((fl & (c1 << 3)) != 0))
			fl = fl & (c2 << 4 | (unsigned char)(7));
		// hrcl
		if ((s[p] == 'b' && s[p + 1] == 'n') && ((fl & (c1 << 4)) != 0))
			fl = fl & (c2 << 5 | (unsigned char)(15));
		if ((s[p] == 'r' && s[p + 1] == 'd') && ((fl & (c1 << 4)) != 0)) {
			fl = fl & (c2 << 5 | (unsigned char)(15));
			x = x | (c1 << 4);
		}
		if ((s[p] == 'b' && s[p + 1] == 'w') && ((fl & (c1 << 4)) != 0)) {
			fl = fl & (c2 << 5 | (unsigned char)(15));
			x = x | (c1 << 5);
		}
		if ((s[p] == 'b' && s[p + 1] == 'k') && ((fl & (c1 << 4)) != 0)) {
			fl = fl & (c2 << 5 | (unsigned char)(15));
			x = x | (c1 << 4);
			x = x | (c1 << 5);
		}
		// eycl
		if ((s[p] =='b' && s[p + 1] == 'u') && ((fl & (c1 << 5)) != 0)) 
			fl = fl & (c2 << 6 | (unsigned char)(31));
		if ((s[p] =='g' && s[p + 1] == 'e') && ((fl & (c1 << 5)) != 0)) {
			fl = fl & (c2 << 6 | (unsigned char)(31));
			x = x | (c1 << 6);
		}
		if ((s[p] =='g' && s[p + 1] == 'y') && ((fl & (c1 << 5)) != 0)) {
			fl = fl & (c2 << 6 | (unsigned char)(31));
			x = x | (c1 << 7);
		}
		if ((s[p] =='d' && s[p + 1] == 'a') && ((fl & (c1 << 5)) != 0)) {
			fl = fl & (c2 << 6 | (unsigned char)(31));
			x = x | (c1 << 6);
			x = x | (c1 << 7);
		}
		p += 3;
		//printf("%hhx\n", x);
	}
	printf("%hhx\n", x);
	return 0;

}