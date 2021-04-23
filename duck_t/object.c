#include <stdio.h>
#include <stdlib.h>

int main() {
	
	unsigned char text[999999]; 
    int fl = 0;
    int size = fread(text, sizeof (unsigned char), 9999999, stdin);
	for (int i = 0; i < size; i++) {
		if (i < size - 2 && (text[i] == 0xD9) && (text[i + 1] == 0x45) && (text[i + 2] == 0x08) && !fl) {
			text[i + 1] = 0xEB;
			text[i + 2] = 0x90;
			fl = 1;
		}
		if (i < size - 1 && text[i] == 0xD8 && text[i + 1] == 0xC1 ) {
			text[i + 1] = 0xC9 ;
		}
	}
	fwrite(text, sizeof(unsigned char), size, stdout);
	return 0;

}
