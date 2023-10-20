#include "monty.h"

/**
 * st_add -  This add function adds the top two elements of the stack.
 * @head: a pointer to stack.
 * @count: line number in Monty ByteCodes file.
 * Return: Nothing.
*/
void st_add(stack_t **head, unsigned int count)
{
	stack_t *node_to_add, *he;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		exitstatus = -1;
		return;
	}

	he = *head;
	node_to_add = he;
	he = he->next;

	he->n = (he->n) + (node_to_add->n);
	free(node_to_add);
}
