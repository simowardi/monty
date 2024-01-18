#include "monty.h"

/**
 * get_next_token - Tokenizes the input into individual tokens
 * @line: Pointer to the input line
 *
 * Return: The next token in the line
 */
char *get_next_token(char **line)
{
	char *token;
	char *delimiters = " \t\n";

	/* Skip leading whitespace */
	*line += strspn(*line, delimiters);

	/* Return NULL if the line is empty or starts with a comment */
	if (**line == '\0' || **line == '#')
		return (NULL);

	/* Find the end of the token */
	token = *line;
	*line += strcspn(*line, delimiters);

	/* Null-terminate the token and move to the next character */
	if (**line != '\0')
	{
		*(*line)++ = '\0';
	}

	return (token);
}

/**
 * get_line_number - Tracks the current line number
 *
 * Return: The current line number
 */
unsigned int get_line_number(void)
{
	static unsigned int line_number;

	return (++line_number);
}

/**
 * free_tokens - Frees the memory allocated to tokens
 * @tokens: Array of tokens to be freed
 */
void free_tokens(char **tokens)
{
	char **current_token = tokens;

	while (*current_token != NULL)
	{
		free(*current_token);
		current_token++;
	}

	free(tokens);
}

/**
 * parse_number - Converts a token to an integer
 * @token: Token to be converted
 *
 * Return: The converted integer
 */
int parse_number(char *token)
{
	return (atoi(token));
}

