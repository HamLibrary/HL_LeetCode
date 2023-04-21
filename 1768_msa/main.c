#include <stdlib.h>

#define mergeAlternately merge_alternatively

char *merge_alternatively(char *a, char *b)
{
	char *buffer = malloc(201);

	int buf_index;
	while (*a && *b)
	{
		buffer[buf_index++] = *a++;
		buffer[buf_index++] = *b++;
	}
	while (*a) buffer[buf_index++] = *a++;
	while (*b) buffer[buf_index++] = *b++;

	buffer[buf_index] = '\0';
	buffer = realloc(buffer, buf_index + 1);
	return buffer;
}
