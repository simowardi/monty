#include "monty.h"

/**
 * main - point of entry
 * @argcount: the count of arguments
 * @argvalist: arguments list
 * Return: always 0
 */

int main(int argcount, char *argvalist[])
{
	if (argcount != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argvalist[1]);
	free_nodes();
	return (0);
}

