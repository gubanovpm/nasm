#include <stdint.h>
typedef uint8_t byte;
typedef uint16_t word;
typedef uint16_t adr;

unsigned char mem[65556];

byte b_read(adr a) {
	return mem[a];
}

void b_write(adr a, byte val) {
	mem[a] = val;
}

word w_read(adr a) {
	return (word)b_read(a) + (word)(b_read(a + 1) << 8);
}

void w_write(adr a, word val) {
	byte hi = val >> 8;
	byte lo = val & 255;
	b_write(a, lo);
	b_write(a + 1, hi);
}