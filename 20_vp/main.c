#include <stdlib.h>
#include <stdbool.h>

#define isValid is_valid

static short counter[126];

bool is_valid___misinterpreted_description(char *s)
{
	counter[40]  = 0; // (
	counter[41]  = 0; // )
	counter[91]  = 0; // [
	counter[93]  = 0; // ]
	counter[123] = 0; // {
	counter[125] = 0; // }

	int index = 0;
	while (s[index])
	{
		++counter[s[index++]];
	}
	
	return ((counter[40] == counter[41]) + (counter[91] == counter[93]) + (counter[123] == counter[125])) == 3;
}

bool is_valid__misinterpreted_again(char *s)
{
	int result = 1;
	int index = 0;
	while (result)
	{
		switch (s[index])
		{
			//    (                        )
			case 40:
				result = (s[index + 1] == 41);
				break;
			//    [                        ]
			case 91:
				result = (s[index + 1] == 93); 
				break;
			//     {                        }
			case 123:
				result = (s[index + 1] == 125);
				break;
			case 0:
				return result;
		}
		index += 2;
	}
	return result;	
}

bool is_valid(char *s)
{
	int bracket_index = 1;
	// Index 0 is not used
	char *bracket_stack = (char *)calloc(2, sizeof(char));

	int result = 1;
	int index = 0;
	while (result)
	{
		switch (s[index])
		{
			case 0:
				result = (bracket_index == 1);
				goto end;
			case 40: case 91: case 123: // '(', '[', '{'
				bracket_stack[bracket_index] = s[index];
				bracket_stack = realloc(bracket_stack, ++bracket_index + 1);
				break;
			case 41:
				result = !(bracket_stack[bracket_index - 1] - '(');
				goto remove_open;
			case 93:
				result = !(bracket_stack[bracket_index - 1] - '[');
				goto remove_open;
			case 125:
				result = !(bracket_stack[bracket_index - 1] - '{');
				remove_open:
				bracket_stack[bracket_index - 1] = 0;
				bracket_stack = realloc(bracket_stack, bracket_index--);
				break;
		}
		++index;
	}

	end:
	free(bracket_stack);
	return result;
}
