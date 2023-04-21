#include <stdlib.h>

#define removeDuplicates remove_duplicates

int remove_duplicates(int *nums, int nums_size)
{
	if (!nums)
		return 0;

	int current_num = nums[0];
	int nums_new_size = 1;
	int replace_index = 0;
	int current_index = 1;

	while (current_index < nums_size)
	{
		if (current_num != nums[current_index])
		{
			nums[replace_index++] = current_num;
			nums_new_size++;
			current_num = nums[current_index];	
		}
		++current_index;
	}

	nums[replace_index] = current_num;
	// nums = realloc(nums, sizeof(int) * nums_new_size);
	return nums_new_size;
}
