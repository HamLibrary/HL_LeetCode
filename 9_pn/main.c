#include <stdbool.h>

#define isPalindrome is_palindrome

bool is_palindrome(int x)
{
	if (x < 0)
		return false;

	int x_copy = x;
	long reversed_x = 0; // long to overcome overflow
	while (!x_copy)
	{
		int remainder = x_copy % 10;
		reversed_x = (reversed_x * 10) + remainder;
		x_copy /= 10;
	}
	return reversed_x == x;
}
