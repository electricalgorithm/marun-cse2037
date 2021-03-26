#include <iostream>

int main() {
	// Part 1
	uint16_t x = 0b1101111011101111;
	uint16_t mask = 0b0000000011111111;
	uint16_t newV = x & mask;
	uint8_t x_low = newV;
	
	// Part 2
	uint8_t x_high = x >> 8;
	
	// Part 3
	uint16_t x_swap = x_low;
	x_swap = x_swap << 8;
	x_swap += x_high;
	
	
	return 0;
}
