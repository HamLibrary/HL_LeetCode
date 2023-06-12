#include <stdlib.h>

#define plusOne plus_one

int *plus_one(int *digits, int digits_size, int *return_size)
{
	// is_overflown tells us if digits and return_arr are out of sync
	int is_overflown = 0, i = 0;
	while (i < digits_size && (is_overflown = (digits[i] == 9)))
		++i;

	*return_size = digits_size + is_overflown;
	int *return_arr = (int *) malloc(sizeof(int) * *return_size);

	int overflow = 1;
	for (i = *return_size - 1;i > 0;--i)
	{
		switch(digits[i - is_overflown] + overflow)
		{
			default:
				goto finishing_touches;
			case 10:
				overflow = 1;
				return_arr[i] = 0;
				break;
		}
	}
	finishing_touches:
	return_arr[i] = (is_overflown) ? 1 : digits[i] + 1;
	
	for (--i;i >= 0;--i)
	{
		return_arr[i] = digits[i]; 
	}
	return return_arr;
}
