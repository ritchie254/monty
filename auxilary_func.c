#include "ritchie.h"
/**
 * error_display - display error message
 * @error: error case
 * Return: display error message and exit status 1
 */
int error_display(int error)
{
	if (error == 0)
		fprintf(stderr, "USAGE: monty file\n");
	else if (error == 1)
		fprintf(stderr, "Error: Can't open file %s\n", global->argv[1]);
	else if (error == 2)
		fprintf(stderr, "Error: malloc failed\n");
	else if (error == 3)
		fprintf(stderr, "L%u: unknown instruction %s\n", global->ln, global->arr[0]);
	else if (error == 4)
		fprintf(stderr, "L%u: usage: push integer\n", global->ln);
	else if (error == 5)
		fprintf(stderr, "L%u: can't %s, stack empty\n", global->ln, global->op);
	else if (error == 6)
		fprintf(stderr, "L%u: can't pop an empty stack\n", global->ln);
	else if (error == 7)
		fprintf(stderr, "L%u: can't %s, stack too short\n", global->ln, global->op);
	else if (error == 8)
		fprintf(stderr, "L%u: division by zero\n", global->ln);
	else if (error == 9)
		fprintf(stderr, "L%u: can't pchar, value out of range\n", global->ln);

	fAll();
	exit(EXIT_FAILURE);
}
/**
 * fAll - free all the memory allocated
 */
void fAll(void)
{
	if (global)
	{
		if (global->stack != NULL)
			fStack(global->stack);
		if (global->command != NULL)
			free(global->command);
		if (global->arr != NULL)
			free(global->arr);
		if (global->fp != NULL)
			fclose(global->fp);
		free(global);
	}
}
/**
 * fStack - free the elements of a stack
 * @stack: stack's head
 */
void fStack(stack_t *stack)
{
	stack_t *current_node;

	while (stack)
	{
		current_node = stack;
		stack = stack->next;
		free(current_node);
	}
}
/**
 * initialize - initialize the elelemnts
 * @global: struct
 * @argv: elements in the CLI
 */
void initialize(global_t *global, char **argv)
{
	global->arr = NULL;
	global->command = NULL;
	global->op = NULL;
	global->status = 0;
	global->ln = 0;
	global->fp = NULL;
	global->stack = NULL;
	global->argv = argv;
}
