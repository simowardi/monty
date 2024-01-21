#include "monty.h"

/**
 * token_args - split line arguments
 * @opcode_line: opcode line in file
 * Return: Nothing
 */
void token_args(char *opcode_line)
{
	int j;
	char *parsed_line; 

	parsed_line = strtok(opcode_line, DELIM);
	j = 0;
	while (parsed_line != NULL)
	{
		args[j] = parsed_line;
		parsed_line = strtok(NULL, DELIM);
		j++;
	}
	args[j] = NULL;
}

