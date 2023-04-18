#include <stdlib.h>
#include <string.h>

#define intToRoman int_to_roman

char *int_to_roman(int num)
{
	char *roman_numeral = (char *)malloc(16); // Longest is 15
	roman_numeral[15] = '\0';
	int index = 14;

	int base = 0;
	char roman_numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	while (num)
	{
		switch (num % 10)
		{
			case 1:
				roman_numeral[index] = roman_numerals[base];
				--index;
				break;
			case 2:
				roman_numeral[index] = roman_numerals[base];
				roman_numeral[index - 1] = roman_numerals[base];
				index -= 2;
				break;
			case 3:
				roman_numeral[index] = roman_numerals[base];
				roman_numeral[index - 1] = roman_numerals[base];
				roman_numeral[index - 2] = roman_numerals[base];
				index -= 3;
				break;
			case 4:
				roman_numeral[index] = roman_numerals[base + 1];
				roman_numeral[index - 1] = roman_numerals[base];
				index -= 2;
				break;
			case 5:
				roman_numeral[index] = roman_numerals[base + 1];
				--index;
				break;
			case 6:
				roman_numeral[index] = roman_numerals[base];
				roman_numeral[index - 1] = roman_numerals[base + 1];
				index -= 2;
				break;
			case 7:
				roman_numeral[index] = roman_numerals[base];
				roman_numeral[index - 1] = roman_numerals[base];
				roman_numeral[index - 2] = roman_numerals[base + 1];
				index -= 3;
				break;
			case 8:
				roman_numeral[index] = roman_numerals[base];
				roman_numeral[index - 1] = roman_numerals[base];
				roman_numeral[index - 2] = roman_numerals[base];
				roman_numeral[index - 3] = roman_numerals[base + 1];
				index -= 4;
				break;
			case 9:
				roman_numeral[index] = roman_numerals[base + 2];
				roman_numeral[index - 1] = roman_numerals[base];
				index -= 2;
		}
		num /= 10;
		base += 2;
	}

	// We add 1 to index by removing 1 from 16
	char *result = (char *)malloc(15 - index);
	memcpy(result, &roman_numeral[index + 1], 15 - index);
	free(roman_numeral);
	return result;
}
