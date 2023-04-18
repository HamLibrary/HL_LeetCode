#include <stdlib.h>
#include <stdbool.h>

#define kidsWithCandies kids_with_candies

bool *kids_with_candies(int *candies, int candies_size, int extra_candies, int *return_size)
{
	*return_size = candies_size;

	int greatest = 0;
	for (int i = 0;i < candies_size;++i)
	{
		if (greatest < candies[i])
			greatest = candies[i];
	}

	bool *return_arr = (bool *)malloc(sizeof(bool) * candies_size);
	for (int i = 0;i < candies_size;++i)
	{
		return_arr[i] = (candies[i] + extra_candies) >= greatest;
	}
	return return_arr;
}
