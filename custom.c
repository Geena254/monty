#include "monty.h"

/**
 * is_int - check that string is int.
 * @string: string to check it.
 * Return: 0 if not and retuen 1 if all is digits.
 */

int is_int(const char *string)
{
	if (*string == '-')
		string++;

	if (*string == '\0')
		return (0);

	do {
		if (!isdigit(*string))
			return (0);
		string++;
	} while (*string != '\0');

	return (1);
}

/**
 * alloc_err - Function that prints an error message.
 * Return: -1
 */

int alloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exitstatus = -1;
	return (-1);
}

/**
 * my_getline - Function clone to getline() function.
 * @line_ptr: buffer to write data to.
 * @buff-size: Initial buffer size.
 * @filestream: File to read from.
 * Return: The length of line.
 */

ssize_t my_getline(char **line_ptr, size_t *buff_size, FILE *filestream)
{
	size_t posi = 0;
	size_t new_buffsize;
	char *new_lineptr;
	int cha;

	if (*line_ptr == NULL)
	{
		*buff_size = 220; /* Adjust initial buffer size as needed */
		*line_ptr = malloc(*buff_size);
		if (*line_ptr == NULL)
			return (alloc_err()); /* Handle aloction error */
	}
	while ((cha = getc(filestream)) != EOF)
	{
		if (posi + 1 >= *buff_size)
		{
			new_buffsize = *buff_size + 10; /* Adjust increment as needed */
			new_lineptr = malloc(new_buffsize);
			if (new_lineptr == NULL)
				return (alloc_err()); /* Handle allocation error */
			memcpy(new_lineptr, *line_ptr, posi);
			free(*line_ptr);
			*line_ptr = new_lineptr;
			*buff_size = new_buffsize;
		}
		(*line_ptr)[posi++] = cha;
		if (cha == '\n')
			break;
	}
	if (posi == 0)
		return (-1); /* Empty line */

	(*line_ptr)[posi] = '\0';
	new_lineptr = malloc(posi + 1);
	if (new_lineptr == NULL)
		return (alloc_err()); /* Handle allocation error */

	memcpy(new_lineptr, *line_ptr, posi + 1);
	free(*line_ptr);
	*line_ptr = new_lineptr;

	return (posi + 1);
}
