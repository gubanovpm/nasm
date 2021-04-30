#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
typedef uint8_t byte;
typedef uint16_t word;
typedef uint16_t adr;

byte mem[65556];

byte b_read(adr a) {
	return mem[a];
}

void b_write(adr a, byte val) {
	mem[a] = val;
}

word w_read(adr a) {
	return (word) b_read(a) + (word)(b_read(a + 1) << 8);
}

void w_write(adr a, word val) {
	byte hi = val >> 8;
	byte lo = val & 255;
	b_write(a, lo);
	b_write(a + 1, hi);
}

void load_file() {

	adr start = 0;
	word n = 0;
	while (scanf("%hx%hx", &start, &n) != EOF)
		for (int i = 0; i < n; i++) {
			byte x = 0;
			scanf("%hhx", &x);
			mem[start + i] = x;
		}
}

void mem_dump(adr start, word n) {
	for (int i = start ; i < start + n; i += 2) {
		printf("%06o : %06o\n", i, (mem[i + 1] << 8) + mem[i]);
	}
}
