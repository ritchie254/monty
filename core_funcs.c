#include "ritchie.h"
/**
 ** op_func - get the operations
 * Return: Op perfoming / message error
 */
void (*op_func(void))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stack},
		{NULL, NULL}
	};

	for (i = 0; op_func[i].opcode != NULL; i++)
	{
		if ((strcmp(global->arr[0], op_func[i].opcode)) == 0)
		{
			global->op = op_func[i].opcode;
			return (op_func[i].f);
		}
	}
	exit(error_display(3));
}
/**
 * split_cmd_line - get line from the file and locate it
 * @line_cmd: string.
 * Return: array of strings.
 */
char **split_cmd_line(char *line_cmd)
{
	int pos = 0;/* position */
	char *word;

	word = strtok(line_cmd, " \n\t");
	while (word != NULL)
	{
		global->arr[pos] = word;
		word = strtok(NULL, " \n\t");
		pos++;
	}
	global->arr[pos] = NULL;
	return (global->arr);
}
