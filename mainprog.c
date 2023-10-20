#include <stdio.h>
#include "monty.h"

/**
 * main - The entry point to start interpreter for Monty ByteCodes files.
 * @argc: The arguments count.
 * @argv: The values passed to the program.
 * Return: 0 on Success
 */

int main(int argc, char **argv)
{
	FILE *opcode_fil;
	char *opcode;
	size_t lineLen = 0;
	unsigned int count = 1;
	stack_t *stack = NULL;
	char *line_buffer = NULL;

	exitstatus = 0;
	/* Check for the correct number of command-line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the Monty ByteCode file */
	opcode_fil = fopen(argv[1], "r");
	if (opcode_fil == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Process Monty instructions line by line */
	while (my_getline(&line_buffer, &lineLen, opcode_fil) != -1)
	{
		if (exitstatus == -1)
			break;

		opcode = strtok(line_buffer, " \t\n"); /* Tokenize the line to extract the instruction */
		execute_inst(opcode, count, &stack);  /* Execute the Monty instruction */

		count++;
		free(line_buffer);
		line_buffer = NULL;
	}
	if (line_buffer != NULL)
		free(line_buffer);

	/* Free memory and close the Monty ByteCode file */
	free_stack(&stack);
	fclose(opcode_fil);
	/* Exit with the appropriate status */
	if (exitstatus == -1)
	{
		fprintf(stderr, "Error encountered during execution\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}
