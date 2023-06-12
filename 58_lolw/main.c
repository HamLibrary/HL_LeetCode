
#define lengthOfLastWord length_of_last_word

int length_of_last_word(char *s)
{
	// -1 prevents 'a' case from making 
	// ((last_space_index + 1) == index) from being true
	int last_space_index = -1;
	int index = 0;

	int word_length = 0;
	while (s[index])
	{
		while (s[index] && s[index] != ' ')
			++index;

		word_length = ((last_space_index + 1) == index) 
		? word_length 
		: index - last_space_index - (index != 0);

		last_space_index = index;
		index += (s[index] != '\0');
	}
	return word_length;
}
