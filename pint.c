#include "monty.h"

/**
 * st_pint - The opcode pint prints the value at the top of the stack.
 * @head: pointer to beginning of stack
 * @count: the line number in Monty ByteCodes file.
 *
 * This function prints the integer value at the top of the stack and handles
 * errors if the stack is empty.
 *
 * Return: void.
 */
void st_pint(stack_t **head, unsigned int count)
{
	/* Check if the stack or the stack's top element is NULL */
	if (head == NULL || *head == NULL)
	{
		/* Print an error message and update the status */
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		exitstatus = -1;
		return;
	}
	/* Print the top element of the stack */
	printf("%d\n", (*head)->n);
}
