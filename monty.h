#ifndef _MONTY_H
#define _MONTY_H

/* libraries */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/* system status */
int exitstatus;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char **argv);
void st_pall(stack_t **head, unsigned int count);
void st_push(stack_t **head, unsigned int count);
void st_pint(stack_t **head, unsigned int count);
void st_pop(stack_t **head, unsigned int count);
void execute_inst(char *opcode, unsigned int line_num, stack_t **stack);
ssize_t my_getline(char **line_ptr, size_t *buff_size, FILE *filestream);

/* free function */
void free_stack(stack_t **stack);

/* util function */
int is_int(const char *string);

#endif /* _MONTY_H */
