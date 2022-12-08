/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:30:53 by frmurcia          #+#    #+#             */
/*   Updated: 2022/12/05 15:30:29 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_stack ft_create_stack_b()
{
	t_stack		stack_b;
	stack_b.lenght = 0;
	stack_b.first = NULL;
	return (stack_b);
}

t_stack	ft_create_stack_a(int argc, char **argv)
{
	t_stack		stack_a;
	t_element 	*tmp;
	t_element	*last;
	int			i;
//Empiezo a crear las piezas y meterlas en stack A
	i = 1;
	while (i < argc)
	{
		tmp = (t_element *)malloc(sizeof(t_element) * 1);
		if (!tmp)
			return (stack_a);
		tmp->value = ft_atoi(argv[i]);
		if(i == 1)
		{
			stack_a.first = tmp;
			tmp->next = NULL;
		}
		else
		{
			last = stack_a.first;
			while(last && last->next != NULL)
			{
				last = last->next;
			}
			last->next = tmp;
			tmp->next = NULL;
		}
		i++;
	}
/*	while (stack_a.first)
	{
		printf("Valor %d\n", stack_a.first->value);
		stack_a.first = stack_a.first->next;
	}*/
	return (stack_a);
}
