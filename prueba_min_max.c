int	ft_max_a(t_stack *stack_a)
{
	t_element	*temp;
	int			cont;

	temp = stack_a->first;
	cont = 0;
	if (stack_a->first == NULL)
		return (0);
	while (temp)
	{
		temp2 = temp;
		while(temp2)
		{
		if (temp2->next && temp2->value > temp2->next->value)
			cont++;
		temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (cont);
}

int	ft_min_a(t_stack *stack_a)
{
	t_element	*temp;
	int			cont;

	temp = stack_a->first;
	cont = 0;
	if (stack_a->first == NULL)
		return (0);
	while (temp)
	{
		if (temp->next && temp->value > temp->next->value)
			cont++;
		temp = temp->next;
	}
	return (cont);
}


void	ft_sort_three(t_stack *stack_a)
{
	int	max;

	max = ft_max_a(stack_a);
	if (max == 1)

}
