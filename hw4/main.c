#include <stdio.h>

/*
 * @author Noah Howard
 * @assignment Homework 4
 *
 * @brief
 * This program creates a series of functions that use bitwise operators to manipulate a set of bits. ISSET will
 * determine if a bit is set at a given position, ADDBIT will add a bit at the supplied position (given that the bit
 * is zero), DELBIT will set the bit in the given position to 0 and PRINTBITS will print the status of 8 bits in a set.
 */

int ISSET(unsigned char bitset, int bitpos);
void ADDBIT(unsigned char* bitset, int bitpos);
void DELBIT(unsigned char* bitset, int bitpos);
void PRINTBITS(unsigned char* bitset);

int main() {
  unsigned char testbit = 0x13;
  printf("Test Bit: %d\n", testbit);

  printf("Is Position 1 set?: %d\n", ISSET(testbit, 1));

  ADDBIT(&testbit, 2);
  printf("Add to position 2: %d\n", testbit);

  testbit = 0x13; // Reset test bit
  DELBIT(&testbit, 1);
  printf("Remove bit at position 1: %d\n\n", testbit);

  PRINTBITS(&testbit);
}

int ISSET(unsigned char bitset, int bitpos) {
  unsigned char bitmask = 0x01;

  if(((bitmask << bitpos) & bitset) > 0) {
    return 1;
  } else {
    return 0;
  }
}

void ADDBIT(unsigned char* bitset, int bitpos) {
  unsigned char bitmask = 0x01;
  *bitset |= (bitmask << bitpos);
}

void DELBIT(unsigned char* bitset, int bitpos) {
  *bitset &= ~(1 << bitpos);
}

void PRINTBITS(unsigned char* num) {
  for(int bit = 0; bit < 8; bit++) {
    printf("The bit in position %d is %i\n", bit, *num & 0x01);
    *num = *num >> 1;
  }
}