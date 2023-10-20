#include "monty.h"

/**
 * free_stack - Function to free a stack.
 * @stack: Pointer to the stack to be freed.
 * Return: Nothing.
 */

void free_stack(stack_t **stack)
{
	stack_t *current_node;
	stack_t *next_node;

	if (stack == NULL || *stack == NULL)
		return;

	current_node = *stack;
	while (!current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*stack = NULL;
}
