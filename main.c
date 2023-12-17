#define _POSIX_C_SOURCE 200809L
#include "ritchie.h"
/**
 * main - Entry point
 * @argc: number ofarguments in command line
 * @argv: string of elements from the command line
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE)
 */
int main(int argc, char **argv)
{
	size_t line_size = 0;

	global = malloc(sizeof(global_t));
	if (global == NULL)
		return (error_display(2));
	initialize(global, argv);

	if (argc != 2)
		return (error_display(0));

	global->fp = fopen(argv[1], "r");
	if (!global->fp)
		return (error_display(1));

	global->arr = malloc(sizeof(char *) * 100);
	if (!global->arr)
		return (error_display(2));

	while (getline(&global->command, &line_size, global->fp) != -1)
	{
		global->ln++;
		split_cmd_line(global->command);

		if (global->arr[0] == NULL || global->arr[0][0] == '#')
			continue;

		op_func()(&global->stack, global->ln);
		free(global->command);
		global->command = NULL;
		line_size = 0;
	}
	fAll();
	return (EXIT_SUCCESS);
}
