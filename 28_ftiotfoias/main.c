#include <string.h>

#define strStr str_first_index_of

int str_first_index_of(char *haystack, char *needle)
{
	if (strlen(haystack) < strlen(needle))
		return -1;

	int haystack_index = 0, needle_index = 0;
	while (haystack[haystack_index])
	{
		while (haystack[haystack_index + needle_index] == needle[needle_index])
		{
			++needle_index;
			if (!needle[needle_index])
				return haystack_index;
		}
		++haystack_index;
		needle_index = 0;
	}
	return -1;
}
