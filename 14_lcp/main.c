#include <stdlib.h>

#define longestCommonPrefix longest_common_prefix

char *longest_common_prefix(char **strs, int strs_size)
{
	int prefix_size = 0;
	char *prefix = (char *)malloc(201);

	int cur_index = 0;
	char cur_check;
	while (strs_size)
	{
		cur_check = strs[0][cur_index];

		for (int i = 0;i < strs_size;++i)
		{
			if (!strs[i][cur_index] || strs[i][cur_index] != cur_check)
				goto found_common_prefix;
		}

		prefix[prefix_size++] = cur_check;
		++cur_index;
	}

	found_common_prefix:
	prefix = (char *)realloc(prefix, prefix_size + 1);
	prefix[prefix_size] = '\0';
	return prefix;
}
