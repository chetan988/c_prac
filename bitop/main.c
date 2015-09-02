#include<stdio.h>
#include<stdlib.h>

int turnoffbit(int, int);
int turnonbit(int, int);
void checkbitwisepallendrun(int);
char swapnibble(int);
void swap(int *, int *);

int main() {

	/* take a number and turn off the bit
	 * Input:  n = 15, k = 1
	 Output: 14
	 Input:  n = 15, k = 2
	 Output: 13
	 */
	/*
	 printf("new value = %d\n",turnoffbit(15,2));
	 printf("new value = %d\n",turnoffbit(15,3));

	 // turn on bit
	 printf("new value = %d\n",turnonbit(0,1));
	 printf("new value = %d\n",turnonbit(0,2));
	 */

	/*
	 * check if bit representation of a number is pallendrum
	 * ex: 110011 is bit wise pallendrun
	 */
	/*
	 unsigned int x = 1<<15 + 1<<16;
	 checkbitwisepallendrun(x);
	 x = 1<<30+1;
	 checkbitwisepallendrun(x);

	 */

	/* swap nibble
	 * ex - 11000110  nibble are 4 bit 1100 and 0110 are nibble
	 * after swap it will look like 01101100
	 */

	/*char x=100;
	 printf("swapped nibble : %d\n",swapnibble(x));
	 */
	/*
	 int x=5,y=10;
	 swap(&x,&y);
	 printf("x=%d  y=%d\n",x,y);
	 */

	return 0;

}

int turnoffbit(int n, int k) {

	int mask = ~(1 << (k - 1)); // ~(000001 << k-1) will result set all bit except kth bit
	return (n & mask);
}

int turnonbit(int n, int k) {
	int mask = (1 << (k - 1)); // will have 1 at kth posistion everything else 0
	return (n | mask);
}

void checkbitwisepallendrun(int x) {
	int l = sizeof(unsigned int) * 8;
	int r = 1;
	int flag = 0;
	while (l > r) {
		if (turnonbit(x, r) != turnonbit(x, l)) {
			flag = 1;
			break;
		}
		l--;
		r++;
	}
	if (flag)
		printf("%d is not pallendrum\n", x);
	else
		printf("%d is pallendrum\n", x);
}

char swapnibble(int x) {
	return (((x & 0x0F) << 4) | ((x & 0xF0) >> 4));
}

void swap(int *x, int *y) {

	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

unsigned int swapBits(unsigned int x) {
	// Get all even bits of x
	unsigned int even_bits = x & 0xAAAAAAAA;

	// Get all odd bits of x
	unsigned int odd_bits = x & 0x55555555;

	even_bits >>= 1;  // Right shift even bits
	odd_bits <<= 1;   // Left shift odd bits

	return (even_bits | odd_bits); // Combine even and odd bits
}

int oppositeSigns(int x, int y) {
	/*
	 * Let the given integers be x and y. The sign bit is 1
	 * in negative numbers, and 0 in positive numbers. The XOR of
	 * x and y will have the sign bit as 1 iff they have opposite sign. In other words,
	 * XOR of x and y will be negative number number iff x and y have opposite signs.
	 *  The following code use this logic
	 */
	if((x ^ y) < 0)
		return 1;
	else
		return 0;
}


