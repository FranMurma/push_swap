/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:48:52 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/24 17:52:06 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_ra(t_stack *stack_a)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (stack_a->lenght == 0 || stack_a->lenght == 1)
		return ;
	else if (stack_a->lenght > 1)
	{
		tmp = stack_a->first;
		tmp2 = stack_a->first;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = tmp2;
		tmp2->prev = tmp;
		stack_a->first = stack_a->first->next;
		stack_a->first->prev = NULL;
		tmp2->next = NULL;
	}
}

void	ft_rb(t_stack *stack_b)
{
	t_element	*tmp;
	t_element	*tmp2;

	if (stack_b->lenght == 0 || stack_b->lenght == 1)
		return ;
	else if (stack_b->lenght > 1)
	{
		tmp = stack_b->first;
		tmp2 = stack_b->first;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = stack_b->first;
		tmp2->prev = tmp;
		stack_b->first = stack_b->first->next;
		stack_b->first->prev = NULL;
		tmp2->next = NULL;
	}
}

void	ft_make_ra(t_stack *stack_a)
{
	ft_ra(stack_a);
}

void	ft_make_rb(t_stack *stack_b)
{
	ft_rb(stack_b);
}

void	ft_make_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}
