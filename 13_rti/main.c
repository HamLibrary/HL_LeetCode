
#define romanToInt roman_to_int

int roman_to_int(char *s)
{
	int output = 0;
	int index = 0;
	
	while (s[index])
	{
		switch (s[index])
		{
			case 'I': // 1
				output += 1;
				break;
			case 'V': // 5
				output += (index && s[index - 1] == 'I') ? 3 : 5;
				break;
			case 'X': // 10
				output += (index && s[index - 1] == 'I') ? 8 : 10;
				break;
			case 'L': // 50
				output += (index && s[index - 1] == 'X') ? 30 : 50;
				break;
			case 'C': // 100
				output += (index && s[index - 1] == 'X') ? 80 : 100;
				break;
			case 'D': // 500
				output += (index && s[index - 1] == 'C') ? 300 : 500;
				break;
			case 'M': // 1000
				output += (index && s[index - 1] == 'C') ? 800 : 1000;
		}
		++index;
	}
	return output;
}
