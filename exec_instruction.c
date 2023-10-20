#include "monty.h"

/**
 * execute_inst - Function to execute Monty ByteCodes.
 * @opcode: instruction to execute.
 * @line_num: number of line of Monty ByteCodes files.
 * @stack: head linked list.
 * Return: Nothing.
 */
void execute_inst(char *opcode, unsigned int line_num, stack_t **stack)
{
	int a = 0;
	instruction_t insts[] = {
		{"push", st_push},
		{"pall", st_pall},
		{"pint", st_pint},
		{"pop", st_pop},
		{NULL, NULL},
	};

	if (opcode == NULL || strcmp("nop", opcode) == 0)
		return;
	if (opcode && opcode[0] == '#')
		return;

	for (; insts[a].opcode != NULL; a++)
	{
		if (strcmp(insts[a].opcode, opcode) == 0)
		{
			insts[a].f(stack, line_num);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	exitstatus = -1;
}
