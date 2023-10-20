#include "monty.h"

/**
 * st_pop - This pop function removes the top element of the stack.
 * @head: pointer to beginning of stack.
 * @count: line number in Monty ByteCodes file.
 * Return: void.
*/
void st_pop(stack_t **head, unsigned int count)
{
	stack_t *node_to_pop;

	/* Check if the stack is empty or invalid */
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		exitstatus = -1;
		return;
	}

	/* Get a reference to the node to be popped */
	node_to_pop = *head;
	(*head) = node_to_pop->next; /* Update the stack to point to next element */
	free(node_to_pop); /* Free the memory of the popped node */
}
