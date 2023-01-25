/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:43:23 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/24 17:51:49 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_pa_sub(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;

	tmp = stack_b->first;
	if (stack_b->lenght > 1)
		stack_b->first = stack_b->first->next;
	else if (stack_b->lenght == 1)
		stack_b->first = NULL;
	tmp->next = stack_a->first;
	tmp->prev = NULL;
	stack_a->first = tmp;
}

void	ft_make_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->lenght == 0)
		return ;
	else if (stack_a->lenght == 0 && stack_b->lenght == 1)
	{
		stack_a->first = stack_b->first;
		stack_b->first = NULL;
	}
	else if (stack_a->lenght == 0 && stack_b->lenght > 1)
	{
		stack_a->first = stack_b->first;
		stack_b->first = stack_b->first->next;
		stack_a->first->next = NULL;
	}
	else if (stack_a->lenght > 0 && stack_b->lenght > 0)
		ft_pa_sub(stack_a, stack_b);
	stack_b->lenght = stack_b->lenght - 1;
	stack_a->lenght = stack_a->lenght + 1;
}

/*Toma el primer elemento  del stack a y lo pone encima del stack b.
No hace nada si a esta vacio.*/
void	ft_pb_sub(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*tmp;

	tmp = stack_a->first;
	if (stack_a->lenght > 1)
		stack_a->first = stack_a->first->next;
	else if (stack_a->lenght == 1)
		stack_a->first = NULL;
	tmp->next = stack_b->first;
	tmp->prev = NULL;
	stack_b->first = tmp;
}

void	ft_make_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->lenght == 0)
		return ;
	else if (stack_b->lenght == 0 && stack_a->lenght == 1)
	{
		stack_b->first = stack_a->first;
		stack_a->first = NULL;
	}
	else if (stack_b->lenght == 0 && stack_a->lenght > 1)
	{
		stack_b->first = stack_a->first;
		stack_a->first = stack_a->first->next;
		stack_b->first->next = NULL;
	}
	else if (stack_a->lenght > 0 && stack_b->lenght > 0)
	{
		ft_pb_sub(stack_a, stack_b);
	}
	stack_b->lenght = stack_b->lenght + 1;
	stack_a->lenght = stack_a->lenght - 1;
}
