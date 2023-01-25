/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:50:21 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/25 17:58:20 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	ft_create_stack_b(void)
{
	t_stack		stack_b;

	stack_b.lenght = 0;
	stack_b.first = NULL;
	return (stack_b);
}

t_stack	ft_pre_create(t_element *tmp, char **argv, int i, t_stack *stack_a)
{
	t_element	*last;

	tmp = (t_element *)malloc(sizeof(t_element) * 1);
	if (!tmp)
		return (*stack_a);
	tmp->value = ft_atoi(argv[i]);
	if (i == 1)
	{
		stack_a->first = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else if (i > 1)
	{
		last = stack_a->first;
		while (last && last->next != NULL)
		{
			last = last->next;
		}
			last->next = tmp;
			tmp->prev = last;
			tmp->next = NULL;
	}
	return (*stack_a);
}

//Creamos las piezas y las metemos en el stack A, pasandolas por atoi.
t_stack	ft_create_stack_a(int argc, char **argv)
{
	t_stack		stack_a;
	t_element	*tmp;
	int			i;

	i = 1;
	stack_a.lenght = 0;
	tmp = NULL;
	while (i < argc)
	{
		stack_a = ft_pre_create(tmp, argv, i, &stack_a);
		i++;
		stack_a.lenght++;
	}
	return (stack_a);
}

//Funcion para liberar las memorias cuando acabo el programa
void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int			i;

	i = 0;
	while (i < stack_a->lenght)
	{
		free(stack_a->first);
		stack_a->first = stack_a->first->next;
		i++;
	}
	i = 0;
	while (i < stack_b->lenght)
	{
		free(stack_b->first);
		stack_b->first = stack_b->first->next;
		i++;
	}
}
