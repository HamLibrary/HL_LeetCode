#include <stdio.h>

#define arraySign array_sign

/*
 * Takes advantage of two's complement
 */
int array_sign(int *nums, int nums_size)
{
	int sign = 1;
	for (int i = 0;i < nums_size;++i)
	{
		if (!nums[i]) return 0;
		sign *= (nums[i] >> 31) + (nums[i] > 0 ? 1 : 0);
	}
	return sign;
}
