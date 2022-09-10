/**
 * push - This function pushes an element into the stack
 * @stack: Stack list
 * @line_number: Line number
 *
 * Return: ...
 */
int push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int i = 0;

	if (!argv[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (-1);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (!isdigit(argv[1][i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (-1);
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	new->n = atoi(argv[1]);
	new->prev = NULL;
	if (!stack || !*stack)
		new->next = NULL;
	else
	{
		(**stack).prev = new;
		new->next = *stack;
	}
	*stack = new;
	if (stacks == 0)
		rotl(stack, line_number);
	return (0);
}
