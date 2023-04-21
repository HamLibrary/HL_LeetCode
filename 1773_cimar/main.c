#include <stdio.h>
#include <string.h>

#define countMatches count_matches

int count_matches(char ***items, int items_size, int *items_col_size, char *rule_key, char *rule_value)
{
	int total_matches = 0;
	int check_index;
	switch((rule_key) ? rule_key[0] : '\0')
	{
		case 't': // Type
			check_index = 0;
			break;
		case 'c': // Color
			check_index = 1;
			break;
		case 'n': // Name
			check_index = 2;
			break;
		default:
			// Invalid rule_key so no matches
			return 0;
	}

	for (int i = 0;i < items_size;++i)
	{
		total_matches += !strcmp(rule_value, items[i][check_index]);
	}
	return total_matches;
}
